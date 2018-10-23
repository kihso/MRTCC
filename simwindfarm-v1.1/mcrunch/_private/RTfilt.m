%=======================================================================
      function FiltPeaks = RTfilt( Peaks, Thresh )
      % Use the racetrack-filter algorithm to eliminate small cycles from the list of peaks .


            % Initialize the algorithm.

         NumPeaks  = size (    Peaks, 1 );
         FiltPeaks = zeros( NumPeaks, 1 );

         S1 = Peaks(1);
         S2 = Peaks(2);

         Ind     = 2;
         NumKept = 0;

         while ( Ind < NumPeaks )

            Ind = Ind + 1;
            S3  = Peaks(Ind);


               % Calculate the absolute difference between data points.

            Diff12 = abs( S1 - S2 );
            Diff23 = abs( S2 - S3 );
            Diff31 = abs( S3 - S1 );


               % Must find the greatest difference.  If difference is greater then the threshold
               % value, continue with the algorithm; otherwise go back and get another data point.

            if ( Diff12 < Thresh )


                  % See if Diff23 is greatest.

               if ( ( Diff23 >= Diff12 ) && ( Diff23 >= Diff31 ) )

      	         S1 = S2;
      	         S2 = S3;

      	         if ( Diff23 >= Thresh ), break, end                % Jump out of this while loop.


                  % See if Diff31 is greatest.

               elseif ( ( Diff31 >= Diff12 ) && ( Diff31 >= Diff23 ) )

      	         S2 = S3;

      	         if ( Diff31 >= Thresh ), break, end                % Jump out of this while loop.

               end% if

            else

               Ind = Ind - 1;                                        % We don't really want to get another data point just yet, so trick it.

               break                                                 % Jump out of this while loop.

            end % if ( Diff12 < Thresh )

         end % while ( Ind < NumPeaks )


            % If Diff32 is greater then the threshold, write s1 to output file
            % and move s1, s2, and s3 forward in the data file by one.
            % If Diff32 is less than the threshold, points must be discarded.

         while ( Ind < NumPeaks )

            Ind = Ind + 1;
            S3  = Peaks(Ind);

            Diff12 = abs( S1 - S2 );
            Diff23 = abs( S2 - S3 );

            if ( Diff23 >= Thresh )

               NumKept = NumKept + 1;

               FiltPeaks(NumKept) = S1;

               S1 = S2;
               S2 = S3;

            else

               Ind = Ind + 1;

               if ( Ind > NumPeaks ), break, end                     % Jump out of this while loop.

               S3 = Peaks(Ind);

               if ( abs( S1 - S3 ) > Diff12 ), S2 = S3; end

            end % if ( Diff23 >= Thresh )

         end % while  ( Ind < NumPeaks )

         FiltPeaks(NumKept+1) = S1;
         FiltPeaks(NumKept+2) = S2;


            % Eliminate the unused elements.

         FiltPeaks(NumKept+3:NumPeaks) = [];

end % function FiltPeaks = RTfilt( Peaks, Thresh )