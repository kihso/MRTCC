%=======================================================================
%TODO: Deal with multiple slopes.
   function [ Cycles, DEL, Bins ] = Rainflow( File, Ch, Range, TimeFact, SNslopes )
   % Finds rainflow cycles in the time series.  Optionally bins the cycles.
   %
   % Cycles(1) = Cycle range for variable means.
   % Cycles(2) = Cycle means.
   % Cycles(3) = Cycle range for fixed means.
   % Cycles(4) = Effective cycle weight.  Use one for full cycles, use UCMult for unclosed cycles.


   global FileInfo Fatigue
   
         % What data channel are we analyzing?

      Chan = Fatigue.ChanInfo(Ch).Chan;


         % Copy the time series for this channel into a temporary array.

      if ( File == 0 )
         TSlen   = FileInfo.TotLines;
         TimeSer = FileInfo.Time(:,Chan);
      else
         TSlen   = FileInfo.NumLines(File);
         TimeSer = FileInfo.Time(FileInfo.StartLine(File):FileInfo.StartLine(File)+TSlen-1,Chan);
      end % if ( File == 0 )


         % Identify peaks and troughs in the time series.  The first and last points are considered peaks or troughs.
         % Sometimes the peaks can be flat for a while, so we have to deal with that nasty situation.

      fprintf( '  Identifying peaks.' );

      [ Peaks, NumPeaks ] = GetPeaks( TimeSer );


         % See if we have at least three points in the Peaks array.

      if ( NumPeaks < 3 )

         if ( File == 0 )
            fprintf( '\n        WARNING: This channel has only %d peaks in the aggregate of all files, so rainflow analysis is not possible.\n\n', NumPeaks );
         else
            fprintf( '\n        WARNING: This channel has only %d peaks in file #%d, so rainflow analysis is not possible.\n\n', NumPeaks, File );
         end % if

         Cycles    = [];
         Bins      = [];
         NumCycles = 0;

         return

      end % if ( NumPeaks < 3 )


         % Optionally use the racetrack filter to eliminate the small cycles.

      if ( Fatigue.FiltRatio > 0 )
         fprintf( '  Applying racetrack filter.' );
         Peaks    = RTfilt( Peaks, Fatigue.FiltRatio*Range );
         NumPeaks = size( Peaks, 1 );
      end % if ( Fatigue.FiltRatio > 0 )


         % See if we still have at least three points in the Peaks array after we've filtered it.

      if ( NumPeaks < 3 )

         beep;

         if ( Fatigue.FiltRatio > 0 )
            fprintf( '\n        WARNING: After applying the racetrack filter and reordering the series, %s has\n', FileInfo.Names{Chan}, NumPeaks );
            fprintf( '                 only %d peaks, so rainflow analysis is not possible for it.\n\n' );
         else
            fprintf( '\n        WARNING: After reordering the series, %s has only %d peaks,\n', FileInfo.Names{Chan}, NumPeaks );
            fprintf( '                 so rainflow analysis is not possible for it.\n\n' );
         end % if ( Fatigue.FiltRatio > 0 )


         Cycles    = [];
         Bins      = [];
         NumCycles = 0;

         return

      end % if ( NumPeaks < 3 )


         % Identify the closed and unclosed cycles.  All cycle ranges, means, and weights are returned in the Cycles array.

      fprintf( '  Finding cycles.' );

      Cycles = GenCycles( Peaks, Fatigue.UCMult, Fatigue.ChanInfo(Ch).LUlt, abs( Fatigue.ChanInfo(Ch).LMF ) );


         % Compute the simple, damage-equivalent loads.

%TODO: Deal with multiple slopes.
      DEL = ( TimeFact*sum( Cycles(:,4).*( Cycles(:,3).^SNslopes ) ) )^( 1/SNslopes );


         % If requested, bin the cycles.

      if ( Fatigue.BinCycles )


         fprintf( '  Binning cycles.' );


            % Set up the bins.

               % If we are binning means, bin the variable-mean cycle ranges (col=1).  If not, bin the
               % fixed-mean cycle ranges (col=3).

               % Do this only on the first pass for this channel.

               % NOTE: In the future, we may ask the user what fraction of the bin
               % width should be the reported value.  To be conservative, we should
               % report the most-positive end of the bin.

         if ( File == 0 )

            if ( Fatigue.BinMeans )

               MeanBinMin = Fatigue.ChanInfo(Ch).BinWidth*floor( min( Cycles(:,2) )/Fatigue.ChanInfo(Ch).BinWidth );
               MeanBinMax = Fatigue.ChanInfo(Ch).BinWidth* ceil( max( Cycles(:,2) )/Fatigue.ChanInfo(Ch).BinWidth );

               Fatigue.Agg.RF(Ch).MBinVals = MeanBinMin:Fatigue.ChanInfo(Ch).BinWidth:MeanBinMax-Fatigue.ChanInfo(Ch).BinWidth;
               Fatigue.Agg.RF(Ch).NumMBins = floor(( MeanBinMax - MeanBinMin )/Fatigue.ChanInfo(Ch).BinWidth);
               Fatigue.Agg.RF(Ch).NumRBins = ceil( Range/Fatigue.ChanInfo(Ch).BinWidth );

               MBinVals = Fatigue.Agg.RF(Ch).MBinVals;

            else

               Fatigue.Agg.RF(Ch).NumMBins = 1;
               Fatigue.Agg.RF(Ch).NumRBins = ceil( max( Cycles(:,3) )/Fatigue.ChanInfo(Ch).BinWidth );

            end % if

            NumRBins = Fatigue.Agg.RF(Ch).NumRBins;
            NumMBins = Fatigue.Agg.RF(Ch).NumMBins;

            Fatigue.Agg.RF(Ch).RBinVals = ( (1:NumRBins) - 0.5 )*Fatigue.ChanInfo(Ch).BinWidth;

         else

            if ( Fatigue.BinMeans )

               MeanBinMin = Fatigue.ChanInfo(Ch).BinWidth*floor( min( Cycles(:,2) )/Fatigue.ChanInfo(Ch).BinWidth );
               MeanBinMax = Fatigue.ChanInfo(Ch).BinWidth* ceil( max( Cycles(:,2) )/Fatigue.ChanInfo(Ch).BinWidth );

               Fatigue.File(File).RF(Ch).MBinVals = MeanBinMin:Fatigue.ChanInfo(Ch).BinWidth:MeanBinMax-Fatigue.ChanInfo(Ch).BinWidth;
               Fatigue.File(File).RF(Ch).NumMBins = floor(( MeanBinMax - MeanBinMin )/Fatigue.ChanInfo(Ch).BinWidth);
               Fatigue.File(File).RF(Ch).NumRBins = ceil( Range/Fatigue.ChanInfo(Ch).BinWidth );

               MBinVals = Fatigue.File(File).RF(Ch).MBinVals;

            else

               Fatigue.File(File).RF(Ch).NumMBins = 1;
               Fatigue.File(File).RF(Ch).NumRBins = ceil( max( Cycles(:,3) )/Fatigue.ChanInfo(Ch).BinWidth );

            end % if

            NumRBins = Fatigue.File(File).RF(Ch).NumRBins;
            NumMBins = Fatigue.File(File).RF(Ch).NumMBins;

            Fatigue.File(File).RF(Ch).RBinVals = ( (1:NumRBins) - 0.5 )*Fatigue.ChanInfo(Ch).BinWidth;

         end % if


            %Initialize the array.

         Bins = zeros( NumRBins, NumMBins );


            % Bin the cycles.

         for Cyc=1:size( Cycles, 1 );

            if ( Fatigue.BinMeans )
               RInd = ceil( Cycles(Cyc,1)/Fatigue.ChanInfo(Ch).BinWidth );
               MInd = max( 1, ceil( ( Cycles(Cyc,2) - MBinVals(1) )/Fatigue.ChanInfo(Ch).BinWidth ) );
            else
               RInd = ceil( Cycles(Cyc,3)/Fatigue.ChanInfo(Ch).BinWidth );
               MInd = 1;
            end % if ( Fatigue.BinMeans )


               % Increment the bin count by the time-factored cycle weight.

%NOTE: Should we just count cycles instead of normalizing with TimeFact?
            Bins(RInd,MInd) = Bins(RInd,MInd) + TimeFact*Cycles(Cyc,4);

         end % for Cyc


            % When doing 2-D binning, let's report the mean bin values as the center of the bins instead of the left edge.

         if ( Fatigue.BinMeans )
            if ( File == 0 )
               Fatigue.Agg.RF(Ch).MBinVals = Fatigue.Agg.RF(Ch).MBinVals + 0.5*Fatigue.ChanInfo(Ch).BinWidth;
            else
               Fatigue.File(File).RF(Ch).MBinVals = Fatigue.File(File).RF(Ch).MBinVals + 0.5*Fatigue.ChanInfo(Ch).BinWidth;
            end % if
         end % if

      else

         Bins = [];

      end % if ( Fatigue.BinCycles )

      fprintf( '\n' );

      return
