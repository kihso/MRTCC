%General
function fatdat=doMCrunch(time,wind,data,names,units,varargin)

clear global AggRoot Binning ChartPosition EchoInp Fatigue FigTitles FileInfo LineWidth OutData PDF ProgName PSD RealFmt SaveFigs StrFmt StrFmtL UnEc;
%global AggRoot Binning ChartPosition EchoInp Fatigue FigTitles FileInfo LineWidth OutData PDF ProgName PSD RealFmt SaveFigs StrFmt StrFmtL UnEc

global  ChartPosition  Fatigue FigTitles FileInfo LineWidth  SaveFigs 

nvar=size(varargin,2);




switch nvar
    case 1
        Fatigue=varargin{1};
     otherwise
        Fatigue.FiltRatio  = 0.05;% 'The fraction of the maximum range of each channel used as a cutoff range for the racetrack filter.' 
        Fatigue.UCMult     = .5;% 'Multiplier for binning unclosed cycles.'                                                           
        Fatigue.RF_Per     = 300;% 'Number of seconds in the rainflow counting period.'                                                 
        Fatigue.RayAverWS  = 10; %'Rayleigh-average wind speed.'                                                                       
        Fatigue.WSmin      = 5; %'Starting value for the wind-speed bins for the Rayleigh distribution.'                       
        Fatigue.WSdel      = .5; % 'Delta value for the wind-speed bins for the Rayleigh distribution.'                                
        Fatigue.BinCycles  = true;% 'Bin the rainflow cycles?'                                                                          
        Fatigue.BinMeans   = false;% 'Bin by cycle means in addition to ranges?'                                                          
        Fatigue.DoSimpDELs = true;%'Compute simple (unweighted) damage-equivalent loads?'                                          
        Fatigue.DoLife     = true; % 'Do lifetime-related calculations?'                                                                  
        Fatigue.PltBinCyc  = true; %'Plot binned rainflow cycles?'                                                                       
        Fatigue.PltProbExc = true; %'Plot probability of exceedance?'                                                                    
        Fatigue.PltCumCyc  = true; %'Plot cumulative rainflow cycles?'                                                                   
        Fatigue.PltRngMean = false; %'Plot 3D range and mean of binned rainflow cycles?'                                                          
end

%No text or excel output
Fatigue.WrRFTxt    = false; %'Write rainflow data to plain-text files?'                                                           
Fatigue.WrRFXLS    = false; %'Write rainflow data to an Excel workbook?'                                                          
Fatigue.WrDELsTxt  = false; %'Write DELs to plain-text files?'                                                                    
Fatigue.WrDELsXLS  = false; %'Write DELs to an Excel workbook?'                                                                   
Fatigue.WrLifeTxt  = true; %'Write lifetime results to plain-text files?'                                                        
Fatigue.WrLifeXLS  = false; %'Write lifetime results to an Excel workbook?'    
Fatigue.TblDELs    = false; %'Generate a table of damage-equivalent loads?'  
%Fatigue.CumFatigue = true;% 'Generate cycle data as cumulative cycles?'                                                                                                               


Fatigue.CumFatigue = Fatigue.WrRFTxt | Fatigue.WrRFXLS | Fatigue.PltCumCyc | Fatigue.PltProbExc;
Fatigue.DoFatPlots = Fatigue.PltBinCyc | Fatigue.PltProbExc | Fatigue.PltCumCyc | Fatigue.PltRngMean | Fatigue.TblDELs;


N=size(data,2);
SettingsFile='NoSettings';

FileInfo.TimeChan=1;
FileInfo.WSChan=2;
FileInfo.TotLines=length(time);
FileInfo.StartLine(1)=1;
FileInfo.NumLines(1)=length(time);
FileInfo.Title={'Turbine data'};
FileInfo.FileName={'NoFile'};

%Data array, time and windspeed in TimeChan and WSChan
FileInfo.Time(:,FileInfo.TimeChan)=time;%Data goes here
FileInfo.Time(:,FileInfo.WSChan)=wind;
FileInfo.Time(:,3:(N+2))=data;


%Channel info
FileInfo.HaveUnits=true*ones(N+2,1);
FileInfo.HaveNames =true*ones(N+2,1);
FileInfo.Names = {'Time','Wind',names{:}};
FileInfo.Units = {'s','m/s',units{:}};
FileInfo.Scales = ones(N+2,1);
FileInfo.Offsets = zeros(N+2,1);

%StrNames = true;%'Use quoted strings of actual channel names instead of numbers?'    ) );
OutData  = false;%'Output modified data array after scaling and calculated channels?' ) );
%RealFmt  = '%11.3e';%'Format for outputting floating-point values.'
%AggRoot  = 'NoFile';% 'Root name for aggregate output files.'                             ) );

%StrFmt  = [ '%' , regexp(RealFmt,'\d*', 'ignorecase', 'match', 'once'), 's' ];
%StrFmtL = [ '%-', regexp(RealFmt,'\d*', 'ignorecase', 'match', 'once'), 's' ];


%Plot Settings
LineWidth     = 1;
FigTitles     = true;
SaveFigs      = false;
ChartPosition = [0, 0, 600, 600];%[FigLeftPos, FigBottomPos, FigWidth, FigHeight];


getStats();

%Statistics, necessary for fatigue analysis
%EEvTable={}; %no Extreme events
%WrStatsTxt   = false; 'Write a text file of statistics for each input file and the aggregate of all of them.';
%WrStatsXLS   = false; 'Write an Excel file of statistics for each input file and the aggregate of all of them.';
%SumStatChans = 3:(N+2);
%NumSFChans   = length(SumStatChans); 'Number of channels that will have summary statistics generated for them.';

%Generate statistics
%GenStats( SumStatChans, WrStatsTxt, WrStatsXLS, SettingsFile );


%Fatigue
DoFatigue=true;
                                                     

%S/N curve
for i=1:N
    %Can not be more than 1 slope atm
    Fatigue.ChanInfo(i).NSlopes =1;
    Fatigue.ChanInfo(i).SNslopes(1)=10;
    Fatigue.ChanInfo(i).Chan    = i+2;
    %If binning is used
    Fatigue.ChanInfo(i).BinWidth = FileInfo.Stats.Range(i+2)/20+1;
    %Fixed load mean
    Fatigue.ChanInfo(i).TypeLMF = 'Value';
    Fatigue.ChanInfo(i).LMF     = FileInfo.Stats.Means(i+2); %hmmm
    %Ultimate load
    Fatigue.ChanInfo(i).LUlt=100*(abs(FileInfo.Stats.Maxima(i+2))+abs(FileInfo.Stats.Minima(i+2)));% ultimate load
end


%Fatigue Plotting
%NumFatFigs =  1; 'Number of figures for the rainflow analysis.';
Fatigue.Plots(1).Name  = 'Fatigue';
Fatigue.Plots(1).NRows = ceil(N/2);
Fatigue.Plots(1).NCols = 2;
Fatigue.Plots(1).Chans = 3:(N+2);
NumFigChans              = size( Fatigue.Plots(1).Chans, 2 );
for SP=1:NumFigChans
    NotFound = true;

    for Ch=1:N
    if ( Fatigue.Plots(1).Chans(SP) == Fatigue.ChanInfo(Ch).Chan )
       Fatigue.Plots(1).FatChan(SP) = Ch;
       NotFound = false;
       break
    end % if
    end % for Ch

    if ( NotFound )
    beep;
    error( [ '\n  For fatigue figure #%d, subplot #%d, the channel specified (%d) is not\n', ...
             '  in the list of fatigue channels.\n\n' ], 1, SP, Fatigue.Plots(1).Chans(SP) );
    end % if

end % for SP


   
% Fatigue Analysis.
if ( DoFatigue )
     settingscheck();
     %CompLife();
     CompFatigue();
     GenRFPlots();
end

fatdat=getFatData();

function settingscheck()

  if ( ~Fatigue.BinCycles && Fatigue.PltBinCyc )
     beep;
     error( '  For fatigue, you must enable binning of cycles (BinCycles) if you want to plot them (PltBinCyc).' );
  end % if

  if ( ~( Fatigue.BinMeans && Fatigue.BinCycles ) && Fatigue.PltRngMean )
     beep;
     error( '  For fatigue, you must enable binning of cycles (BinCycles) and binning of cycle means (BinMeans) if you want to plot them (PltRngMean).' );
  end % if

  if ( Fatigue.BinMeans && Fatigue.DoLife )
     beep;
     error( '  For fatigue, do not enable binning of cycle means (BinMeans) if you want to do fatigue-life calculations (DoLife).' );
  end % if

  if ( ~Fatigue.BinCycles && Fatigue.DoLife )
     beep;
     error( '  For fatigue, you must enable binning of cycles (BinCycles) if you want to do fatigue-life calculations (DoLife).' );
  end % if

  if ( Fatigue.DoLife && ( Fatigue.RayAverWS <= 0 ) )
     beep;
     error( '  For fatigue, the Rayleigh-average wind speed (RayAverWS) must be greater than zero.' );
  end % if

  if ( Fatigue.DoLife && ( Fatigue.WSdel <= 0 ) )
     beep;
     error( '  For fatigue, the delta value for the wind-speed bins for the Rayleigh distribution (WSdel) must be greater than zero.' );
  end % if

  if ( Fatigue.DoLife && ( FileInfo.WSChan == 0 ) )
     beep;
     error( '  For fatigue, you cannot do lifetime calculations without specifying the wind-speed channel (WSChan).' );
  end % if

  if ( Fatigue.DoLife && ~( Fatigue.WrLifeTxt || Fatigue.WrLifeXLS ) )
     beep;
     error( '  For fatigue, you are doing lifetime calculations, but you are not asking for output (WrLifeTxt or WrLifeXLS).' );
  end % if
end

end

