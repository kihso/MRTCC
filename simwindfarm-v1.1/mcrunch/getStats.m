function getStats()
% Generate statistics of data.
%
% This function calculates the following statistics for data
% stored in the FileInfo data structure:
%     Minimum plus corresponding index
%     Mean
%     Maximum plus corresponding index
%     Standard Deviation
%     Skewness
%     Range (Maximum-Minimum)
%
% It process all datasets in the structure and adds the statistics
% to the original data structure.
%
% Syntax is:  GenStats( SumStatChans, WrStatsTxt, WrStatsXLS )
%
%     where:
%        SumStatChans:  A double array of channel numbers for which summary
%                       statistics are desired.
%        WrStatsTxt:    A boolean scalar that indicates if the user wants the
%                       statistics written to a plain text file.
%        WrStatsXLS:    A boolean scalar that indicates if the user wants the
%                       statistics written to an Excel workbook.
%
% Example:
%     GenStats( [ 1, 5, 9 ], false, true )
%
% See also DelFile, DelSheet1, GetRoot, MCrunch, ReadSettings

   global AggRoot FileInfo ProgName RealFmt StrFmt

   NumCols = size( FileInfo.Names, 2 );

   % Initialize and set the class for the indices.

   NumFiles = size( FileInfo.FileName, 1 );
   NumChans = size( FileInfo.Names   , 2 );

   FileInfo.Stats.MinInds = zeros( NumFiles, NumChans, 'uint32' );
   FileInfo.Stats.MaxInds = zeros( NumFiles, NumChans, 'uint32' );


   % No sense doing aggregate statistics if only one file is being processed.

   if ( NumFiles > 1 )
      FileInfo.Stats.AggMinInds = zeros( 1, NumChans, 'uint32' );
      FileInfo.Stats.AggMaxInds = zeros( 1, NumChans, 'uint32' );

      FirstFile = 0;
   else
      FirstFile = 1;
   end


      % Process the aggregate if appropriate and individual data sets in the structure.

   for File=FirstFile:NumFiles


         % Compute statistics.

      CompStats( File );


         % Create plain-text statistics files if requested.
   end


      % Create an Excel workbook with one sheet for the aggregate and one
      % for each file if requested.

      % Generate summary statistics of selected files.

  % for C=1:size( SumStatChans, 2 );
   %   GenSumStats( SumStatChans(C) );
   %end % for

   return
%===============================================================================
   function CompStats( File )

      if ( File == 0 )                                         % Aggregate statistics.

         RowRange = 1:FileInfo.TotLines;


            % Generate statistics.

         %fprintf( '  Generating aggregate statistics.\n' );

         [ FileInfo.Stats.AggMinima, FileInfo.Stats.AggMinInds ] = min( FileInfo.Time(RowRange,:) );
         [ FileInfo.Stats.AggMaxima, FileInfo.Stats.AggMaxInds ] = max( FileInfo.Time(RowRange,:) );

         FileInfo.Stats.AggMeans   = mean    ( FileInfo.Time(RowRange,:) );
         FileInfo.Stats.AggStdDevs = std     ( FileInfo.Time(RowRange,:) );
         FileInfo.Stats.AggSkews   = skewness( FileInfo.Time(RowRange,:) );

         FileInfo.Stats.AggRange = FileInfo.Stats.AggMaxima - FileInfo.Stats.AggMinima;


            % Check for constant data.  Correct skewness if it is.

         for Chan=1:size( FileInfo.Names, 2 )

            if ( FileInfo.Stats.AggRange(Chan) <= realmin )
               FileInfo.Stats.AggSkews(Chan) = 0;
            end % if

         end % for

      else                                                     % Individual-file statistics.

      RowRange = FileInfo.StartLine(File) : ( FileInfo.StartLine(File) + FileInfo.NumLines(File) - 1 );


            % Generate statistics.

      %   fprintf( '  Generating statistics for "%s".\n', FileInfo.FileName{File} );

         [ FileInfo.Stats.Minima(File,:), FileInfo.Stats.MinInds(File,:) ] = min( FileInfo.Time(RowRange,:) );
         [ FileInfo.Stats.Maxima(File,:), FileInfo.Stats.MaxInds(File,:) ] = max( FileInfo.Time(RowRange,:) );

         FileInfo.Stats.Means  (File,:) = mean    ( FileInfo.Time(RowRange,:) );
         FileInfo.Stats.StdDevs(File,:) = std     ( FileInfo.Time(RowRange,:) );
         FileInfo.Stats.Skews  (File,:) = skewness( FileInfo.Time(RowRange,:) );

         FileInfo.Stats.Range(File,:) = FileInfo.Stats.Maxima(File,:) - FileInfo.Stats.Minima(File,:);


            % Check for constant data.  Correct skewness if it is.

         for Chan=1:size( FileInfo.Names, 2 )

            if ( FileInfo.Stats.Range(File,Chan) <= realmin )
               FileInfo.Stats.Skews(File,Chan) = 0;
            end % if

         end % for

      end % if

      return

   end % function CompStats
%===============================================================================
  
end % GenStats
