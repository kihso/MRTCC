%=======================================================================
      function [ Peaks, NumPeaks ] = GetPeaks( TimeSer )
      % Identify peaks and troughs in the time series.  The first and last points are considered peaks or troughs.
      % Sometimes the peaks can be flat for a while, so we have to deal with that nasty situation.

         Peaks    = TimeSer;
         NumPeaks = 1;
         LastDiff = 1;
         TSlen    = size( TimeSer, 1 );

         for Pt=2:(TSlen-1)

            if ( TimeSer(Pt) == TimeSer(Pt+1) )                                                               % Is slope zero?  Don't update LastDiff is so.
               continue;
            elseif ( ( sign( TimeSer(Pt) - TimeSer(LastDiff) ) + sign( TimeSer(Pt+1) - TimeSer(Pt) ) ) ==  0 )    % Did slope change sign?
               NumPeaks        = NumPeaks + 1;
               Peaks(NumPeaks) = TimeSer(Pt);
            end % if

            LastDiff = Pt;

         end % for Pt


            % Add the last point of the time series to the list of peaks.

         Peaks    = [ Peaks(1:NumPeaks); TimeSer(TSlen) ];
         NumPeaks = NumPeaks + 1;

      end % function [ Peaks, NumPeaks ] = GetPeaks( TimeSer )
