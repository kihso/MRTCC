function GenRFPlots( SettingsFile )
% Plot the results of the rainflow analysis done by CompFatigue.
%
% Several plot types are available:
%     Binned rainflow cycles
%     Probability of exceedance
%     Cumulative rainflow cycles
%     3-D range and mean binned rainflow cycles
%
% Syntax is:  GenRFPlots( SettingsFile );
%
% Example:
%     GenRFPlots( 'MySettings.mcru' );
%
% See also CompFatigue, GetRoot, MCrunch, ReadSettings

   global ChartPosition Fatigue FileInfo HdlFig LineWidth PlotColors SaveFigs

   PlotColors = [ 'r', 'b', 'c', 'm', 'g', 'k', 'y', 'w' ];
   Markers    = [ 'o', 's', 'd', '.', 'x', 'p', 'h', '*' ];

   if ( Fatigue.PltBinCyc || Fatigue.PltCumCyc || Fatigue.PltProbExc || Fatigue.PltRngMean )
      fprintf( '  Generating fatigue plots:\n' );
   end % if

   HdlFig = [];
   Title  = [];


      % Generate the requested plots.

   if ( Fatigue.PltBinCyc )
      fprintf( '    Binned rainflow-cycle plots.\n' );
      GenPltBinCyc;
   end % if

   if ( Fatigue.PltCumCyc )
      fprintf( '    Cumulative rainflow-cycle plots.\n' );
      GenPltCumCyc;
   end % if

   if ( Fatigue.PltProbExc )
      fprintf( '    Probability of exceedance plots.\n' );
      GenPltProbExc;
   end % if

   if ( Fatigue.PltRngMean )

      if ( size( FileInfo.FileName, 1 ) > 1 )
         beep;
         error( '\n  It is not possible to generate 3-D range/mean rainflow plots for more than one file.\n\n' );
      end % if

      fprintf( '    3-D range and mean plots of binned rainflow cycles.\n' );
      GenPltRngMean;

   end % if

   if ( Fatigue.PltBinCyc || Fatigue.PltCumCyc || Fatigue.PltProbExc || Fatigue.PltRngMean )
      fprintf( '  Done.\n' );
   end % if

   return
%=======================================================================
   function FinalizePlt( Fig, HdlSP, HdlTit )

      set( HdlSP(2), 'Units','normalized' );
  %    SPos = get( HdlSP(2),  'position' );


         % Get the title position title.

      TExt = get( HdlTit, 'position' );


         % Create the legend and put it below the title.

      if ( size( FileInfo.FileName, 1 ) > 1 )
         HdlLeg = legend( [ FileInfo.FileName; 'Aggregate' ], 'interpreter','none', 'FontSize',7, 'location', 'NorthOutside' );
         set( HdlLeg, 'Units','normalized' );
         LPos = get( HdlLeg, 'position' );
         set( HdlLeg, 'Position', [ 0.5-LPos(3)/2, 1-TExt(4)-LPos(4), LPos(3), LPos(4) ] );
         LPos = get( HdlLeg, 'Position' );
      else
         LPos = zeros( 4, 1 );
      end % if


         % Resize the subplots so the title and legend don't cover any of them.

      SPht = ( 1.0 - LPos(4) - TExt(4) - 0.03 )/Fatigue.Plots(Fig).NRows - 0.1;

      for Row=1:Fatigue.Plots(Fig).NRows
         for Col=1:Fatigue.Plots(Fig).NCols
            SP    = ( Row - 1 )*Fatigue.Plots(Fig).NCols + Col;
            if(SP<=length(Fatigue.Plots(Fig)))
                SPos = get( HdlSP(SP), 'position' );
                Yloc  = 0.1 + ( Fatigue.Plots(Fig).NRows - Row )*( SPht + 0.1 );
                set( HdlSP(SP), 'position', [ SPos(1), Yloc, SPos(3), SPht ] );
            end
         end % for Col
      end % for Row

      if ( SaveFigs )
         saveas( HdlFig, [ Title, '.fig' ] )
      end % if

  %    if ( Fatigue.PrFatPlots )
  %       print
  %    end % if

      return

   end % function FinalizePlt( Fig, HdlSP, Title )
%=======================================================================
   function GenPltBinCyc
   % Plot binned rainflow cycles.

         % Plot the figure(s).

      for Fig=1:size( Fatigue.Plots, 2 )

         HdlFig = figure( 10000+Fig );
         set( HdlFig, 'Position', ChartPosition );
         Title  = [ 'Binned Rainflow Cycles of ', Fatigue.Plots(Fig).Name ];
         HdlTxt = text( 0, 0, Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold', 'Units','normalized' );
         TitExt = get( HdlTxt, 'extent' );
         close( HdlFig );
         HdlFig = figure( 10000+Fig );

         set( HdlFig, 'Position', ChartPosition );


            % Add an overall title that is centered at the top of the figure.

         HdlTit = annotation('textbox', 'String',Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold' );
         set( HdlTit, 'Color', [0.0, 0.0, 1.0 ], 'LineStyle','none' );
         set( HdlTit, 'Units','normalized', 'HorizontalAlignment','center', 'VerticalAlignment','top' );
         set( HdlTit, 'Position', [ 0.5*(1-TitExt(3)), 1-TitExt(4), TitExt(3), TitExt(4) ] )


            % This is the Figure/Window title.

         set( HdlFig, 'Color',[1 1 1], 'Name',Title, 'NumberTitle','off', 'PaperOrientation','landscape', 'PaperSize',[11.0, 8.5], 'PaperPosition',[0.25 0.75 10.5 7.0], 'PaperType','usletter' );


            % Add the subplots.

         for SP=1:size( Fatigue.Plots(Fig).Chans, 2 )

            FatChan = Fatigue.Plots(Fig).FatChan(SP);
            Chan    = Fatigue.Plots(Fig).Chans(SP);

            HdlSP(SP) = subplot( Fatigue.Plots(Fig).NRows, Fatigue.Plots(Fig).NCols, SP );


               % Add curve for each case, including the aggregate, to the plot.

            for File=1:size( FileInfo.FileName, 1 )

               Color  = PlotColors( mod( File-1, 5 ) + 1 );
               Marker = Markers   ( mod( File, 8 ) );

               semilogy( Fatigue.File(File).RF(FatChan).RBinVals, Fatigue.File(File).RF(FatChan).Bins, 'LineStyle','none', 'Marker',Marker, 'MarkerEdgeColor',Color, 'MarkerFaceColor',Color, 'MarkerSize',4  );

               hold on;

            end % for File

            if ( size( Fatigue.File, 2 ) > 1 )
               semilogy( Fatigue.Agg.RF(FatChan).RBinVals, Fatigue.Agg.RF(FatChan).Bins, 'LineStyle', 'none', 'Marker', '+', 'MarkerEdgeColor', 'k', 'MarkerFaceColor', 'k', 'MarkerSize', 4 );
            end % if

            hold off


               % Label it and make it pretty.

            set( gca, 'FontName','Trebuchet MS', 'FontSize',11, 'FontWeight','bold', 'LineWidth',1.2, 'XColor',[0 0 0], 'YColor',[0 0 0] );
            grid on;

            if ( FileInfo.HaveNames )
               if ( FileInfo.HaveUnits )
                  xlabel( [ FileInfo.Names{Chan},' Range ',FileInfo.Units{Chan} ], 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );
               else
                  xlabel( [ FileInfo.Names{Chan},' Range' ], 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );
               end % if
            end % if

            ylabel( Fatigue.RFPerStr, 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );

         end % for SP


            % Finalize plots with legend and resize it.

         FinalizePlt( Fig, HdlSP, HdlTit );

      end % for Fig

      return

   end % function GenPltBinCyc
%=======================================================================
   function GenPltCumCyc
   % Plot cumulative rainflow cycles.


         % Plot the figure(s).

      for Fig=1:size( Fatigue.Plots, 2 )

         HdlFig = figure( 11000+Fig );
         set( HdlFig, 'Position', ChartPosition );
         Title  = [ 'Cumulative Rainflow Cycles of ', Fatigue.Plots(Fig).Name ];
         HdlTxt = text( 0, 0, Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold', 'Units','normalized' );
         TitExt = get( HdlTxt, 'extent' );
         close( HdlFig );
         HdlFig = figure( 11000+Fig );

         set( HdlFig, 'Position', ChartPosition );


            % Add an overall title that is centered at the top of the figure.

         HdlTit = annotation('textbox', 'String',Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold' );
         set( HdlTit, 'Color', [0.0, 0.0, 1.0 ], 'LineStyle','none' );
         set( HdlTit, 'Units','normalized', 'HorizontalAlignment','center', 'VerticalAlignment','top' );
         set( HdlTit, 'Position', [ 0.5*(1-TitExt(3)), 1-TitExt(4), TitExt(3), TitExt(4) ] )


            % This is the Figure/Window title.

         set( HdlFig, 'Color',[1 1 1], 'Name',Title, 'NumberTitle','off', 'PaperOrientation','landscape', 'PaperSize',[11.0, 8.5], 'PaperPosition',[0.25 0.75 10.5 7.0], 'PaperType','usletter' );


            % Add the subplots.

         for SP=1:size( Fatigue.Plots(Fig).Chans, 2 )

            FatChan = Fatigue.Plots(Fig).FatChan(SP);
            Chan    = Fatigue.Plots(Fig).Chans(SP);

            HdlSP(SP) = subplot( Fatigue.Plots(Fig).NRows, Fatigue.Plots(Fig).NCols, SP );


               % Add curve for each case, including the aggregate, to the plot.

            for File=1:size( FileInfo.FileName, 1 )

               Color  = PlotColors( mod( File-1, 5 ) + 1 );

               semilogy( Fatigue.File(File).RF(FatChan).CumCycles(:,1), Fatigue.File(File).RF(FatChan).CumCycles(:,2), Color, 'LineWidth', LineWidth  );

               hold on;

            end % for File

            if ( size( Fatigue.File, 2 ) > 1 )
               semilogy( Fatigue.Agg.RF(FatChan).CumCycles(:,1), Fatigue.Agg.RF(FatChan).CumCycles(:,2), 'k', 'LineWidth', LineWidth );
            end % if

            hold off


               % Label it and make it pretty.

            set( gca, 'FontName','Trebuchet MS', 'FontSize',11, 'FontWeight','bold', 'LineWidth',1.2, 'XColor',[0 0 0], 'YColor',[0 0 0] );
            grid on;

            if ( FileInfo.HaveNames )
               if ( FileInfo.HaveUnits )
                  xlabel( [ FileInfo.Names{Chan},' Range ',FileInfo.Units{Chan} ], 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );
               else
                  xlabel( [ FileInfo.Names{Chan},' Range' ], 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );
               end % if
            end % if

            ylabel( [ 'Cum. ', Fatigue.RFPerStr ], 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );

         end % for SP


            % Finalize plots with legend and resize it.

         FinalizePlt( Fig, HdlSP, HdlTit );

      end % for Fig

      return

   end % function GenPltCumCyc
%=======================================================================
   function GenPltProbExc
   % Plot probability of exceedance for rainflow-cycles.


         % Plot the figure(s).

      for Fig=1:size( Fatigue.Plots, 2 )

         HdlFig = figure( 12000+Fig );
         set( HdlFig, 'Position', ChartPosition );
         Title  = [ 'Rainflow-Cycle Exceedance Probabilities of ', Fatigue.Plots(Fig).Name ];
         HdlTxt = text( 0, 0, Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold', 'Units','normalized' );
         TitExt = get( HdlTxt, 'extent' );
         close( HdlFig );
         HdlFig = figure( 12000+Fig );

         set( HdlFig, 'Position', ChartPosition );


            % Add an overall title that is centered at the top of the figure.

         HdlTit = annotation('textbox', 'String',Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold' );
         set( HdlTit, 'Color', [0.0, 0.0, 1.0 ], 'LineStyle','none' );
         set( HdlTit, 'Units','normalized', 'HorizontalAlignment','center', 'VerticalAlignment','top' );
    %     TPos   = get( HdlTit, 'Position' );
         set( HdlTit, 'Position', [ 0.5*(1-TitExt(3)), 1-TitExt(4), TitExt(3), TitExt(4) ] )


            % This is the Figure/Window title.

         set( HdlFig, 'Color',[1 1 1], 'Name',Title, 'NumberTitle','off', 'PaperOrientation','landscape', 'PaperSize',[11.0, 8.5], 'PaperPosition',[0.25 0.75 10.5 7.0], 'PaperType','usletter' );


            % Add the subplots.

         for SP=1:size( Fatigue.Plots(Fig).Chans, 2 )

            FatChan = Fatigue.Plots(Fig).FatChan(SP);
            Chan    = Fatigue.Plots(Fig).Chans(SP);

            HdlSP(SP) = subplot( Fatigue.Plots(Fig).NRows, Fatigue.Plots(Fig).NCols, SP );


               % Add curve for each case to the plot.

            for File=1:size( FileInfo.FileName, 1 )

               Color  = PlotColors( mod( File-1, 5 ) + 1 );
               Marker = Markers   ( mod( File, 8 ) );

               AryLen = size( Fatigue.File(File).RF(FatChan).CumCycles, 1 );

               semilogx( Fatigue.File(File).RF(FatChan).CumCycles(2:2:AryLen,1), Fatigue.File(File).RF(FatChan).CumCycles(2:2:AryLen,2)/Fatigue.File(File).RF(FatChan).CumCycles(AryLen,2), ...
                         Color, 'LineStyle', 'none', 'Marker', Marker, 'MarkerEdgeColor', Color, 'MarkerFaceColor', Color, 'MarkerSize', 4  );

               hold on;

            end % for File


               % Add curve for the aggregate to the plot.

            if ( size( Fatigue.File, 2 ) > 1 )

               AryLen = size( Fatigue.Agg.RF(FatChan).CumCycles, 1 );

               semilogx( Fatigue.Agg.RF(FatChan).CumCycles(2:2:AryLen,1), Fatigue.Agg.RF(FatChan).CumCycles(2:2:AryLen,2)/Fatigue.Agg.RF(FatChan).CumCycles(AryLen,2), ...
                         'LineStyle', 'none', 'Marker', '+', 'MarkerEdgeColor', 'k', 'MarkerFaceColor', 'k', 'MarkerSize', 4  );

            end % if

            hold off


               % Label it and make it pretty.

            set( gca, 'FontName','Trebuchet MS', 'FontSize',11, 'FontWeight','bold', 'LineWidth',1.2, 'XColor',[0 0 0], 'YColor',[0 0 0] );
            grid on;

            if ( FileInfo.HaveNames )
               if ( FileInfo.HaveUnits )
                  xlabel( [FileInfo.Names{Chan},' Range ',FileInfo.Units{Chan}], 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );
               else
                  xlabel( [FileInfo.Names{Chan},' Range'], 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );
               end % if
            end % if

            ylabel( 'Prob. of Exceedance', 'FontName','Trebuchet MS', 'FontSize',14, 'FontWeight','bold' );

         end % for SP


            % Finalize plots with legend and resize it.

         FinalizePlt( Fig, HdlSP, HdlTit );

      end % for Fig

      return

   end % function GenPltProbExc
%=======================================================================
   function GenPltRngMean
   % Plot 3-D ranges and means of binned rainflow cycles.


         % Plot the figure(s).

      for Fig=1:size( Fatigue.Plots, 2 )


            % Close it if it alread exists.

         HdlFig = figure( 13000+Fig );
         set( HdlFig, 'Position', ChartPosition );
         Title  = [ 'Binned Range/Mean Rainflow Cycles of ', Fatigue.Plots(Fig).Name ];
         HdlTxt = text( 0, 0, Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold', 'Units','normalized' );
         TitExt = get( HdlTxt, 'extent' );
         close( HdlFig );
         HdlFig = figure( 13000+Fig );

         set( HdlFig, 'Position', ChartPosition );


            % Add an overall title that is centered at the top of the figure.

         HdlTit = annotation('textbox', 'String',Title, 'FontName','Trebuchet MS', 'FontSize',16, 'FontWeight','bold' );
         set( HdlTit, 'Color', [0.0, 0.0, 1.0 ], 'LineStyle','none' );
         set( HdlTit, 'Units','normalized', 'HorizontalAlignment','center', 'VerticalAlignment','top' );
     %    TPos   = get( HdlTit, 'Position' );
         set( HdlTit, 'Position', [ 0.5*(1-TitExt(3)), 1-TitExt(4), TitExt(3), TitExt(4) ] )


            % This is the Figure/Window title.

         set( HdlFig, 'Color',[1 1 1], 'Name',Title, 'NumberTitle','off', 'PaperOrientation','landscape', 'PaperSize',[11.0, 8.5], 'PaperPosition',[0.25 0.75 10.5 7.0], 'PaperType','usletter' );


            % Add the subplots.

         for SP=1:size( Fatigue.Plots(Fig).Chans, 2 )

            FatChan = Fatigue.Plots(Fig).FatChan(SP);
            Chan    = Fatigue.Plots(Fig).Chans(SP);

     %       HdlSP(SP) = subplot( Fatigue.Plots(Fig).NRows, Fatigue.Plots(Fig).NCols, SP );
            subplot( Fatigue.Plots(Fig).NRows, Fatigue.Plots(Fig).NCols, SP );


               % Add surface to the plot.
%TODO: Where is File defined?
            meshc( Fatigue.File.RF(FatChan).MBinVals', Fatigue.File.RF(FatChan).RBinVals', Fatigue.File.RF(FatChan).Bins );


               % Label it and make it pretty.

            set( gca, 'FontName','Trebuchet MS', 'FontSize',10, 'FontWeight','bold', 'LineWidth',1.2, 'XColor',[0 0 0], 'YColor',[0 0 0], ...
                      'PlotBoxAspectRatio',[ 1, 1, 1.3 ] );
            grid off;
            xlabel( ' Mean ' , 'FontName','Trebuchet MS', 'FontSize',10, 'FontWeight','bold' );
            ylabel( ' Range ', 'FontName','Trebuchet MS', 'FontSize',10, 'FontWeight','bold' );
            zlabel( Fatigue.RFPerStr, 'FontName','Trebuchet MS', 'FontSize',10, 'FontWeight','bold' );

            if ( FileInfo.HaveNames )
               if ( FileInfo.HaveUnits )
                  text( .5, -.2, 0, [ FileInfo.Names{Chan},' ',FileInfo.Units{Chan} ], 'Interpreter','none', 'FontName','Trebuchet MS', 'FontWeight','bold', 'FontSize',11, ...
                        'Color',[0, 0, 1], 'HorizontalAlignment','center', 'LineStyle','none', 'Units','normalized' );
               else
                  text( .5, -.2, 0, FileInfo.Names{Chan}, 'Interpreter','none', 'FontName','Trebuchet MS', 'FontWeight','bold', 'FontSize',11, ...
                        'Color',[0, 0, 1], 'HorizontalAlignment','center', 'LineStyle','none', 'Units','normalized' );
               end % if
            end % if

         end % for SP

      end % for Fig

      return

   end % function GenPltRngMean
%=======================================================================
   function GenTblDELhtml
   % Generate a table of damage-equivalent loads.  Table is in HTML format.

      global RealFmt


         % Open the HTML file for writing.
         % Add the header information.

      HTMLfile = [ GetRoot( SettingsFile ), '_DEL.html' ];
      UnH = fopen( HTMLfile, 'wt' );

      if ( UnH < 0 )
         beep
         error( sprintf( '  Could not open "%s" for writing.', HTMLfile ) );
      end

      fprintf( UnH, '<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">\n' );
      fprintf( UnH, '<html>\n' );
      fprintf( UnH, '<head><title>Table of Damage-Equivalent Loads</title></head>\n' );
      fprintf( UnH, '<body>\n' );
      fprintf( UnH, '<center><h2><font color="navy">Damage-Equivalent Loads</font></h2>\n' );


         % Set up a table to display the DELs.

      NumFiles = size( FileInfo.FileName, 1 );

      fprintf( UnH, '<table border="0" cellpadding="1" width="100%%">\n' );


         % Generate the header of the table.

      fprintf( UnH, '<tr><th align="left">Channel</th><th align="center">Units</th><th align="center">S/N Slope</th>' );

      if ( NumFiles == 1 )

         fprintf( UnH, '<th align="right">DEL</th></tr>\n' );

      else

         fprintf( UnH, '<th align="right"><font color="navy">Aggregate</font></th>' );

         NumStr = sprintf( '%d', ceil( log10( NumFiles ) ) );

         for File=1:NumFiles
            fprintf( UnH, [ '<th align="right">File%', NumStr, 'd</th>' ], File );
         end % for File

         fprintf( UnH, '</tr>\n' );

      end % if


         % Generate the body of the table.

      for Ch=1:size( Fatigue.ChanInfo, 2 )

         fprintf( UnH, '<tr><td align="left">%-10s</td><td align="center">%-10s</td><td align="center">%d</td>', Fatigue.ChanInfo(Ch).ChanName, FileInfo.Units{Fatigue.ChanInfo(Ch).Chan}, Fatigue.ChanInfo(Ch).SNslope );

         if ( NumFiles == 1 )

            fprintf( UnH, [ '<td align="right">', RealFmt, '</td></tr>\n' ], Fatigue.File(1).RF(Ch).DEL );

         else

            fprintf( UnH, [ '<td align="right"><font color="navy">', RealFmt, '</font></td>' ], Fatigue.Agg.RF(Ch).DEL );

            for File=1:NumFiles
               fprintf( UnH, [ '<td align="right">', RealFmt, '</td>' ], Fatigue.File(File).RF(Ch).DEL );
            end % for File

            fprintf( UnH, '</tr>\n' );

         end % if

      end % for


         % End the table.

      fprintf( UnH, '</table>\n' );


         % Create a new table of file names.

      fprintf( UnH, '<br><table border="0" cellpadding="1" width="100%%">\n' );

      if ( NumFiles == 1 )
         fprintf( UnH, '<tr><td>&nbsp;</td><td align="center">File: %s</td></tr>\n', FileInfo.FileName{1} );
      else
         for File=1:NumFiles
            fprintf( UnH, [ '<tr><td>&nbsp;</td><td align="left">File%', NumStr, 'd: %s</td></tr>\n' ], File, FileInfo.FileName{File} );
         end % for
      end % if


         % End the table.

      fprintf( UnH, '</table>\n' );


         % Close the HTML file and display it on screen.

      fclose( UnH );

  %    web( HTMLfile, '-new' );           % Uses the MatLab web browser.
      web( HTMLfile, '-browser' );        % Uses the computer's default web browser.

      return

   end % function GenTblDELhtml
%=======================================================================
end % function GenRFPlots( SettingsFile )
