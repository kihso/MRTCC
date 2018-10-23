%=======================================================================
      function Cycles = GenCycles( Peaks, UCMult, LUlt, LMF )
      % Generate rainflow cycles.

      % Algorithm obtained from:

      %     Ariduru, Se�il (2004).  "Fatigue Life Calculation by Rainflow Cycle Counting Method."
      %     M.S. Thesis.  Ankara, Turkey: Middle East Technical University.

      % The example used in Section 3.2 of the thesis was used to debug this routine.
      % This routine also gives the exact same answers as Crunch.



            % Process the peaks and valleys.

         NumPeaks    = size( Peaks, 1 );
         RemainPeaks = zeros( NumPeaks, 1 );
         Ind         = 0;
         LenUC       = 0;
         NumCycles   = 0;
         Cycles      = zeros( int32( size( Peaks, 1 )/2 - 0.5 ), 4 );
         LFMargin    = LUlt - LMF;

         while ( true )


            if ( Ind < NumPeaks )

               Ind = Ind + 1;

               if ( Ind > NumPeaks ), break, end

               LenUC              = LenUC + 1;
               RemainPeaks(LenUC) = Peaks(Ind);

            end % if ( Ind < NumPeaks )


               % Make sure we have at least three peaks in the RemainPeaksing array.

            while ( LenUC < 3 )

               Ind = Ind + 1;

               if ( Ind > NumPeaks ), break, end

               LenUC              = LenUC + 1;
               RemainPeaks(LenUC) = Peaks(Ind);

            end % while ( LenUC < 3 )


               % Compute the newest and oldest active ranges.

            OldRange = abs( RemainPeaks(LenUC-1) - RemainPeaks(LenUC-2) );
            NewRange = abs( RemainPeaks(LenUC  ) - RemainPeaks(LenUC-1) );


               % If the new range is as large as the oldest active range, we found a cycle.
               % If LenUC is 3, it's a half cycle.  Add it to the list of cycles.

            while ( NewRange >= OldRange )

               NumCycles = NumCycles + 1;

               Cycles(NumCycles,1) = OldRange;
               Cycles(NumCycles,2) = 0.5*( RemainPeaks(LenUC-1) + RemainPeaks(LenUC-2) );
               Cycles(NumCycles,3) = Cycles(NumCycles,1)*LFMargin/( LUlt - abs( Cycles(NumCycles,2) ) );

               if ( LenUC > 3 )
                  Cycles(NumCycles,4)              = 1.0;
                  RemainPeaks((LenUC-2):(LenUC-1)) = [];
                  LenUC                            = LenUC - 2;
               else
                  Cycles(NumCycles,4)    = UCMult;
                  RemainPeaks((LenUC-2)) = [];
                  LenUC                  = LenUC - 1;
               end % if ( LenUC > 3 )

               if ( LenUC >= 3 )
                  OldRange = abs( RemainPeaks(LenUC-1) - RemainPeaks(LenUC-2) );
                  NewRange = abs( RemainPeaks(LenUC  ) - RemainPeaks(LenUC-1) );
               else
                  NewRange = -1;
               end % if ( LenUC >= 3 )

            end % while ( NewRange >= OldRange )

            if ( Ind == NumPeaks ), break, end

         end % while


            % Add the unclosed cycles to the end of the Cycles matrix if the weight is not zero.

         if ( ( LenUC > 1 ) && ( UCMult > 0 ) )

            for Cyc=1:LenUC-1
               Cycles(NumCycles+Cyc,1) = abs ( RemainPeaks(Cyc) - RemainPeaks(Cyc+1) );
               Cycles(NumCycles+Cyc,2) = 0.5*( RemainPeaks(Cyc) + RemainPeaks(Cyc+1) );
               Cycles(NumCycles+Cyc,3) = Cycles(NumCycles+Cyc,1)*LFMargin/( LUlt - abs( Cycles(NumCycles+Cyc,2) ) );
               Cycles(NumCycles+Cyc,4) = UCMult;
            end % for Cyc

         else

            LenUC = 1;

         end % if ( ( LenUC > 1 ) && ( UCMult > 0 ) )


            % Truncate the unused portion of the array.

         TotCycles = NumCycles + LenUC - 1;
         Cycles    = Cycles(1:TotCycles,:);


      end % function Cycles = GenCycles( Peaks, UCMult )
