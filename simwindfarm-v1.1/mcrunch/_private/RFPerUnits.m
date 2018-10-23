%=======================================================================
   function RFPerStr = RFPerUnits( RF_Per )
   % Determine the units string for the rainflow period.


      if ( RF_Per == 1.0 )

         RFPerStr = 'Cycles per Second';

%      elseif ( RF_Per < 60.0 )
%
%         RFPerStr = sprintf( 'Cycles per %g Seconds', RF_Per );
%
      elseif ( mod( RF_Per, 31536000.0 ) == 0.0 )

         if ( RF_Per == 31536000.0 )
            RFPerStr = 'Cycles per Year';
         else
            RFPerStr = sprintf( 'Cycles per %g Years', RF_Per/31536000.0 );
         end % if

      elseif ( mod( RF_Per, 86400.0 ) == 0.0 )

         if ( RF_Per == 86400.0 )
            RFPerStr = 'Cycles per Day';
         else
            RFPerStr = sprintf( 'Cycles per %g Days', RF_Per/86400.0 );
         end % if

      elseif ( mod( RF_Per, 3600.0 ) == 0.0 )

         if ( RF_Per == 3600.0 )
            RFPerStr = 'Cycles per Hour';
         else
            RFPerStr = sprintf( 'Cycles per %g Hours', RF_Per/3600.0 );
         end % if

      elseif ( mod( RF_Per, 60.0 ) == 0.0 )

         if ( RF_Per == 60.0 )
            RFPerStr = 'Cycles per Minute';
         else
            RFPerStr = sprintf( 'Cycles per %g Minutes', RF_Per/60.0 );
         end % if

      else

         RFPerStr = sprintf( 'Cycles per %g Seconds', RF_Per );

      end % if

   end % function RFPerStr = RFPerUnits( RF_Per )