function CompFatigue( SettingsFile )
% Perform a fatigue anaylsis.
%
% For now, it does a rainflow analysis and calculates damage equivalent loads
% for individual times series.  The DELs are not weighted by a probability
% distribution.
%
% Syntax is:  CompFatigue( SettingsFile );
%
% Example:
%     CompFatigue( 'MySettings.mcru' );
%
% See also DelFile, GetRoot, MCrunch, ReadSettings

   global FileInfo Fatigue


      % Tell the user we are doing a fatigue analysis.

   fprintf( '\n  Performing fatigue analysis.\n' );


      % Eliminate any selected channels that are constant or determine the number of bins
      % if we are binning the cycles.

   NumFatChan = size( Fatigue.ChanInfo , 2 );
   NumFiles   = size( FileInfo.FileName, 1 );

   if ( NumFiles > 1 )
      DoAgg = true;
   else
      DoAgg = false;
   end % if ( NumFiles > 1 )

   Range  = zeros( 1, NumFatChan );
   Minima = zeros( 1, NumFatChan );
   Maxima = zeros( 1, NumFatChan );

   AllConstant = true;


      % Compute the time elapsed in each file.

   for File=1:NumFiles
      BegTime                = FileInfo.Time(FileInfo.StartLine(File)                          ,FileInfo.TimeChan);
      EndTime                = FileInfo.Time(FileInfo.StartLine(File)+FileInfo.NumLines(File)-1,FileInfo.TimeChan);
      Fatigue.ElapTime(File) = EndTime - BegTime;
   end % for File


      % Calculate the bin probabilities for the wind-speed bins.

   if ( Fatigue.DoLife )


         % Of all the files, what is the largest mean wind speed?

      MaxAver = 0;

      for File=1:NumFiles
         if ( FileInfo.Stats.Means(File,FileInfo.WSChan) > MaxAver )
            MaxAver = FileInfo.Stats.Means(File,FileInfo.WSChan);
         end % if
      end % for File


         % Determine the probability for each wind-speed bin using the Rayleigh distribution.

      NumWSbins      = ceil( ( MaxAver - Fatigue.WSmin )/Fatigue.WSdel );
      Fatigue.WSProb = zeros( NumWSbins, 1 );
%      MPi2Vavg       = -0.25*pi/Fatigue.RayAverWS^2;
      AvSR2byPi      = Fatigue.RayAverWS*sqrt( 2/pi );

      for Bin=1:NumWSbins
         WShi                = Fatigue.WSmin + Bin*Fatigue.WSdel;
         WSlo                = WShi - Fatigue.WSdel;
%         Fatigue.WSProb(Bin) = exp( MPi2Vavg*WSlo^2 ) - exp( MPi2Vavg*WShi^2 );
         Fatigue.WSProb(Bin) = raylcdf( WShi, AvSR2byPi ) - raylcdf( WSlo, AvSR2byPi );
      end % for Bin


         % Compute the total time in each wind-speed bin.

      Fatigue.Time = zeros( NumWSbins, 1 );

      for File=1:NumFiles
         WSbin                  = ceil( ( FileInfo.Stats.Means(File,FileInfo.WSChan) - Fatigue.WSmin )/Fatigue.WSdel );
         Fatigue.Time(WSbin)    = Fatigue.Time(WSbin) + Fatigue.ElapTime(File);
      end % for File

   end % if ( Fatigue.DoLife )


   for Ch=1:NumFatChan

      Chan                          = Fatigue.ChanInfo(Ch).Chan;
      Fatigue.ChanInfo(Ch).ChanName = FileInfo.Names{Chan};

      if ( DoAgg )
         Range (Ch) = FileInfo.Stats.AggRange (Chan);
         Minima(Ch) = FileInfo.Stats.AggMinima(Chan);
         Maxima(Ch) = FileInfo.Stats.AggMaxima(Chan);
      else
         Range (Ch) = FileInfo.Stats.Range (Chan);
         Minima(Ch) = FileInfo.Stats.Minima(Chan);
         Maxima(Ch) = FileInfo.Stats.Maxima(Chan);
      end % if ( DoAgg )

   end % for Ch


      % See if all the channels have constant data.  If so, we are done.

   if ( max( Range ) == 0.0 )
      beep;
      error( '\n  All selected fatigue columns have constant data.  Fatigue calculations skipped.\n' );
   end % if


      % Delete any old information.  Create the Cycles and Bins branches.

   if ( DoAgg )
      Fatigue.Agg.RF(1:NumFatChan) = struct( 'NumCCycles', [], 'Cycles', [], 'Bins', [] );
   end % if ( DoAgg )

   Fatigue.File(NumFiles).RF(NumFatChan) = struct( 'NumCCycles', [], 'Cycles', [], 'Bins', [] );


      % Set the string for the RF period.

 %  if ( Fatigue.BinCycles )
      Fatigue.RFPerStr = RFPerUnits( Fatigue.RF_Per );
 %  end % if


      % Process the aggregate (if more than one) and all the files.

   if ( DoAgg )
      FirstFile = 0;
   else
      FirstFile = 1;
   end % if ( DoAgg )

   for File=FirstFile:NumFiles


         % If we are binning cycles, determine the time scale factor.
         % If the RF period is 0, just count cycles.
         % We are assuming that the data has a constant time step and
         % that the first file has at least to time steps.

      if ( File == 0 )
         fprintf( '    Performing fatigue analysis of aggregate data:\n' );
         NumLines = size( FileInfo.Time, 1 ) - 1;
      else
         NumLines = FileInfo.NumLines(File) - 1;
      end % if ( File == 0 )

      if ( Fatigue.BinCycles )

         if ( Fatigue.RF_Per == 0 )
            TimeFact = 1;
         else
            if ( File == 0 )
               TimeFact = Fatigue.RF_Per/sum( Fatigue.ElapTime );
            else
               TimeFact = Fatigue.RF_Per/Fatigue.ElapTime(File);
            end % if
         end % if ( Fatigue.RF_Per == 0 )

      else

         if ( File == 0 )
            TimeFact = 1.0/sum( Fatigue.ElapTime );
         else
            TimeFact = 1.0/Fatigue.ElapTime(File);
         end % if

      end % if


         % Loop through the channels.  Cycle count, then bin the cycles if requested.

      for Ch=1:size( Fatigue.ChanInfo, 2 )

         Chan = Fatigue.ChanInfo(Ch).Chan;

         fprintf( '      %s:', FileInfo.Names{Chan} )

%TODO: Deal with multiple slopes.
         if ( File == 0 )
            [ Fatigue.Agg.RF(Ch).Cycles, Fatigue.Agg.RF(Ch).DEL, Fatigue.Agg.RF(Ch).Bins ] = Rainflow( File, Ch, Range(Ch), TimeFact, Fatigue.ChanInfo(Ch).SNslopes );
         else
            [ Fatigue.File(File).RF(Ch).Cycles, Fatigue.File(File).RF(Ch).DEL, Fatigue.File(File).RF(Ch).Bins ] = Rainflow( File, Ch, Range(Ch), TimeFact, Fatigue.ChanInfo(Ch).SNslopes );
         end % if ( File == 0 )


            % Accumulate cycles if requested.

         if ( Fatigue.CumFatigue )

            if ( File == 0 )

               NumCycles  = size( Fatigue.Agg.RF(Ch).Cycles, 1 );

               SortCycles = sortrows( [ Fatigue.Agg.RF(Ch).Cycles(:,3), Fatigue.Agg.RF(Ch).Cycles(:,4) ], -1 );
               Fatigue.Agg.RF(Ch).CumCycles = zeros( 2*NumCycles, 2 );

               Fatigue.Agg.RF(Ch).CumCycles(1:2,1) = [ SortCycles(1,1); SortCycles(1,1) ];
               Fatigue.Agg.RF(Ch).CumCycles(2,2)   = SortCycles(1,2);

               for Cyc=2:NumCycles
                  Fatigue.Agg.RF(Ch).CumCycles(2*Cyc-1:2*Cyc,1) = [ SortCycles(Cyc,1); SortCycles(Cyc,1) ];
                  Fatigue.Agg.RF(Ch).CumCycles(2*Cyc-1,2) = Fatigue.Agg.RF(Ch).CumCycles(2*Cyc-2,2);
                  Fatigue.Agg.RF(Ch).CumCycles(2*Cyc  ,2) = Fatigue.Agg.RF(Ch).CumCycles(2*Cyc-1,2) + SortCycles(Cyc,2);
               end % for Cyc

            else

               NumCycles  = size( Fatigue.File(File).RF(Ch).Cycles, 1 );

               SortCycles = sortrows( [ Fatigue.File(File).RF(Ch).Cycles(:,3), Fatigue.File(File).RF(Ch).Cycles(:,4) ], -1 );
               Fatigue.File(File).RF(Ch).CumCycles = zeros( 2*NumCycles, 2 );

               Fatigue.File(File).RF(Ch).CumCycles(1:2,1) = [ SortCycles(1,1); SortCycles(1,1) ];
               Fatigue.File(File).RF(Ch).CumCycles(2,2)   = SortCycles(1,2);

               for Cyc=2:NumCycles
                  Fatigue.File(File).RF(Ch).CumCycles(2*Cyc-1:2*Cyc,1) = [ SortCycles(Cyc,1); SortCycles(Cyc,1) ];
                  Fatigue.File(File).RF(Ch).CumCycles(2*Cyc-1,2) = Fatigue.File(File).RF(Ch).CumCycles(2*Cyc-2,2);
                  Fatigue.File(File).RF(Ch).CumCycles(2*Cyc  ,2) = Fatigue.File(File).RF(Ch).CumCycles(2*Cyc-1,2) + SortCycles(Cyc,2);
               end % for Cyc

            end % if ( File == 0 )

         end % if

      end % for Ch

   end % for File


      % If requested, do the lifetime calculations.

   if ( Fatigue.DoLife && ( File > 0 ) )
      CompLife( File, Ch );
   end % if


         % When plotting range/mean bins, search for vectors of all zeros from both sides of
         % the Bins matrix and eliminate them.  Eliminate the elements of MBinVals too.

   if ( Fatigue.PltRngMean )

      for Ch=1:size( Fatigue.ChanInfo, 2 )

         for MInd=1:Fatigue.File.RF(Ch).NumMBins
            if ( std( Fatigue.File.RF(Ch).Bins(:,MInd) ) > 0.0 );
               if ( MInd > 1 )
                  Fatigue.File.RF(Ch).Bins(:,1:MInd-1) = [];
                  Fatigue.File.RF(Ch).MBinVals(:,1:MInd-1) = [];
                  Fatigue.File.RF(Ch).NumMBins = Fatigue.File.RF(Ch).NumMBins - MInd + 1;
               end % if
               break
            end % if
         end % for MInd

         for MInd=Fatigue.File.RF(Ch).NumMBins:-1:1
            if ( std( Fatigue.File.RF(Ch).Bins(:,MInd) ) > 0.0 );
               if ( MInd < Fatigue.File.RF(Ch).NumMBins )
                  Fatigue.File.RF(Ch).Bins(:,MInd+1:Fatigue.File.RF(Ch).NumMBins) = [];
                  Fatigue.File.RF(Ch).MBinVals(MInd+1:Fatigue.File.RF(Ch).NumMBins) = [];
                  Fatigue.File.RF(Ch).NumMBins = MInd;
               end % if
               break
            end % if
         end % for MInd

      end % for Ch
   end % if


      % Write out results.

   fprintf( '  Done.\n' );

   return

%=======================================================================
  function CompLife( File, Ch )
   % Compute the life.
    
        
      Fatigue.Damage = zeros( NumFatChan, 1 );
        
      
      for File=1:NumFiles

         WSbin = ceil( ( FileInfo.Stats.Means(File,FileInfo.WSChan) - Fatigue.WSmin )/Fatigue.WSdel );

         for Ch=1:NumFatChan
            for Bin=1:Fatigue.File(File).RF(Ch).NumRBins
               Cycles2Fail        = ( ( Fatigue.ChanInfo(Ch).LUlt - Fatigue.ChanInfo(Ch).LMF )/( 0.5*Fatigue.File(File).RF(Ch).RBinVals(Bin) ) )^Fatigue.ChanInfo(Ch).SNslopes(1);
               LifeCycles         = Fatigue.WSProb(WSbin)*Fatigue.File(File).RF(Ch).Bins(Bin)*Fatigue.ElapTime(File)/Fatigue.Time(WSbin);
               Fatigue.Damage(Ch) = Fatigue.Damage(Ch) + LifeCycles/Cycles2Fail;
            end % for Bin
         end % for Ch

      end % for File


      return
  end
%=======================================================================
end % CompFatiguee( SettingsFile )
