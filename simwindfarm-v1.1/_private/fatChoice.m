function varargout = fatChoice(varargin)
% FATCHOICE M-file for fatChoice.fig
%      FATCHOICE, by itself, creates a new FATCHOICE or raises the existing
%      singleton*.
%
%      H = FATCHOICE returns the handle to a new FATCHOICE or the handle to
%      the existing singleton*.
%
%      FATCHOICE('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in FATCHOICE.M with the given input arguments.
%
%      FATCHOICE('Property','Value',...) creates a new FATCHOICE or raises
%      the existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before fatChoice_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to fatChoice_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help fatChoice

% Last Modified by GUIDE v2.5 17-Mar-2014 11:13:55

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @fatChoice_OpeningFcn, ...
                   'gui_OutputFcn',  @fatChoice_OutputFcn, ...
                   'gui_LayoutFcn',  @fatChoice_LayoutFcn, ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT

% --- Executes just before fatChoice is made visible.
function fatChoice_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to fatChoice (see VARARGIN)

% Choose default command line output for fatChoice
handles.fighandle = hObject;
handles.choices={};

% Update handles structure
guidata(hObject, handles);



% UIWAIT makes fatChoice wait for user response (see UIRESUME)
uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = fatChoice_OutputFcn(hObject, eventdata, handles)
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{2} = handles.fighandle;
varargout{1} = handles.choices;
%Close the window
close(handles.figure1);

% --- Executes on button press in Ok.
function Ok_Callback(hObject, eventdata, handles)
% hObject    handle to Ok (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

handles.choices.DoLife=get(handles.doLifecheckbox,'value');
handles.choices.DoSimpDEL=get(handles.delcheckbox,'value');
handles.choices.BinCycles=get(handles.bincheckbox,'value');
handles.choices.BinMeans=get(handles.meancheckbox,'value');
handles.choices.PltBinCyc=get(handles.pbincheckbox,'value');
handles.choices.PltRngMean=get(handles.groupmeancheckbox,'value');
handles.choices.PltCumCyc=get(handles.pcumcheckbox,'value');
handles.choices.PltProbExc=get(handles.pexceedcheckbox,'value');

% Update handles structure
guidata(hObject, handles);

%Close figure
uiresume(handles.figure1);


% --- Executes on button press in Ok.
function Cancel_Callback(hObject, eventdata, handles)
% hObject    handle to Ok (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
uiresume(handles.figure1);








% --- Executes on button press in pbincheckbox.
function pbincheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to pbincheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of pbincheckbox


% --- Executes on button press in pcumcheckbox.
function pcumcheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to pcumcheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of pcumcheckbox


% --- Executes on button press in groupmeancheckbox.
function groupmeancheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to groupmeancheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of groupmeancheckbox


% --- Executes on button press in pexceedcheckbox.
function pexceedcheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to pexceedcheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of pexceedcheckbox


% --- Executes on button press in doLifecheckbox.
function doLifecheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to doLifecheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of doLifecheckbox


% --- Executes on button press in delcheckbox.
function delcheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to delcheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of delcheckbox


% --- Executes on button press in meancheckbox.
function meancheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to meancheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of meancheckbox


% --- Executes on button press in bincheckbox.
function bincheckbox_Callback(hObject, eventdata, handles)
% hObject    handle to bincheckbox (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of bincheckbox


% --- Creates and returns a handle to the GUI figure. 
function h1 = fatChoice_LayoutFcn(policy)
% policy - create a new figure or use a singleton. 'new' or 'reuse'.

persistent hsingleton;
if strcmpi(policy, 'reuse') & ishandle(hsingleton)
    h1 = hsingleton;
    return;
end

appdata = [];
appdata.GUIDEOptions = struct(...
    'active_h', [], ...
    'taginfo', struct(...
    'figure', 2, ...
    'pushbutton', 9, ...
    'text', 15, ...
    'edit', 6, ...
    'frame', 4, ...
    'radiobutton', 19, ...
    'uipanel', 12, ...
    'checkbox', 10), ...
    'override', 1, ...
    'release', 13, ...
    'resize', 'simple', ...
    'accessibility', 'callback', ...
    'mfile', 1, ...
    'callbacks', 1, ...
    'singleton', 1, ...
    'syscolorfig', 1, ...
    'blocking', 0, ...
    'lastSavedFile', '/Users/mikael/Documents/SimWindFarm/git_afs/private/fatChoice.m', ...
    'lastFilename', '/Users/mikael/Documents/SimWindFarm/git_afs/private/FatigueChoices.fig');
appdata.lastValidTag = 'figure1';
appdata.GUIDELayoutEditor = [];
appdata.initTags = struct(...
    'handle', [], ...
    'tag', 'figure1');

h1 = figure(...
'PaperUnits','centimeters',...
'Color',[0.929411764705882 0.929411764705882 0.929411764705882],...
'Colormap',[0 0 0.5625;0 0 0.625;0 0 0.6875;0 0 0.75;0 0 0.8125;0 0 0.875;0 0 0.9375;0 0 1;0 0.0625 1;0 0.125 1;0 0.1875 1;0 0.25 1;0 0.3125 1;0 0.375 1;0 0.4375 1;0 0.5 1;0 0.5625 1;0 0.625 1;0 0.6875 1;0 0.75 1;0 0.8125 1;0 0.875 1;0 0.9375 1;0 1 1;0.0625 1 1;0.125 1 0.9375;0.1875 1 0.875;0.25 1 0.8125;0.3125 1 0.75;0.375 1 0.6875;0.4375 1 0.625;0.5 1 0.5625;0.5625 1 0.5;0.625 1 0.4375;0.6875 1 0.375;0.75 1 0.3125;0.8125 1 0.25;0.875 1 0.1875;0.9375 1 0.125;1 1 0.0625;1 1 0;1 0.9375 0;1 0.875 0;1 0.8125 0;1 0.75 0;1 0.6875 0;1 0.625 0;1 0.5625 0;1 0.5 0;1 0.4375 0;1 0.375 0;1 0.3125 0;1 0.25 0;1 0.1875 0;1 0.125 0;1 0.0625 0;1 0 0;0.9375 0 0;0.875 0 0;0.8125 0 0;0.75 0 0;0.6875 0 0;0.625 0 0;0.5625 0 0],...
'DockControls','off',...
'IntegerHandle','off',...
'InvertHardcopy',get(0,'defaultfigureInvertHardcopy'),...
'MenuBar','none',...
'Name','FatigueChoices',...
'NumberTitle','off',...
'PaperPosition',get(0,'defaultfigurePaperPosition'),...
'PaperSize',[20.98404194812 29.67743169791],...
'PaperType','A4',...
'Position',[544 350 211 275],...
'HandleVisibility','callback',...
'UserData',[],...
'Tag','figure1',...
'Visible','on',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'Cancel';

h2 = uicontrol(...
'Parent',h1,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('Cancel_Callback',hObject,eventdata,guidata(hObject)),...
'CData',[],...
'FontSize',9.99999999999999,...
'ListboxTop',0,...
'Position',[0.531707317073171 0.0178571428571429 0.307317073170732 0.167857142857143],...
'String','Cancel',...
'UserData',[],...
'Tag','Cancel',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'Ok';

h3 = uicontrol(...
'Parent',h1,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('Ok_Callback',hObject,eventdata,guidata(hObject)),...
'CData',[],...
'FontSize',9.99999999999999,...
'ListboxTop',0,...
'Position',[0.136585365853659 0.0178571428571429 0.317073170731707 0.167857142857143],...
'String','OK',...
'UserData',[],...
'Tag','Ok',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'unitgroup';

h4 = uibuttongroup(...
'Parent',h1,...
'FontSize',9.99999999999996,...
'Title','Options',...
'Clipping','on',...
'Position',[0.0128156565656566 0.603225806451613 0.941666666666666 0.348387096774194],...
'Tag','unitgroup',...
'SelectedObject',[],...
'SelectionChangeFcn',@(hObject,eventdata)fatChoice('unitgroup_SelectionChangeFcn',get(hObject,'SelectedObject'),eventdata,guidata(get(hObject,'SelectedObject'))),...
'OldSelectedObject',[],...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'doLifecheckbox';

h5 = uicontrol(...
'Parent',h4,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('doLifecheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999997,...
'Position',[0.037037037037037 0.8125 0.931216931216931 0.1625],...
'String','Do Lifetime Calculations',...
'Style','checkbox',...
'Value',1,...
'Tag','doLifecheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'delcheckbox';

h6 = uicontrol(...
'Parent',h4,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('delcheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999997,...
'Position',[0.037037037037037 0.575 0.894179894179894 0.175],...
'String','Do Simple DEL',...
'Style','checkbox',...
'Tag','delcheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'meancheckbox';

h7 = uicontrol(...
'Parent',h4,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('meancheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999997,...
'Position',[0.037037037037037 0.0375 0.931216931216931 0.25],...
'String','Calculate Bin Means',...
'Style','checkbox',...
'Tag','meancheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'bincheckbox';

h8 = uicontrol(...
'Parent',h4,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('bincheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999997,...
'Position',[0.037037037037037 0.325 0.894179894179894 0.2],...
'String','Bin Rainflow Cycles',...
'Style','checkbox',...
'Value',1,...
'Tag','bincheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'uipanel11';

h9 = uibuttongroup(...
'Parent',h1,...
'FontSize',9.99999999999996,...
'Title','Plots',...
'Clipping','on',...
'Position',[0.00975609756097561 0.218376623376623 0.941463414634146 0.371428571428571],...
'Tag','uipanel11',...
'SelectedObject',[],...
'SelectionChangeFcn',[],...
'OldSelectedObject',[],...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'pbincheckbox';

h10 = uicontrol(...
'Parent',h9,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('pbincheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999998,...
'Position',[0.0423280423280423 0.816091954022988 0.904761904761905 0.149425287356322],...
'String','Plot Binned Cycles',...
'Style','checkbox',...
'Value',1,...
'Tag','pbincheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'pcumcheckbox';

h11 = uicontrol(...
'Parent',h9,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('pcumcheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999998,...
'Position',[0.0423280423280423 0.333333333333333 0.894179894179894 0.17283950617284],...
'String','Plot Cumulative Cycles',...
'Style','checkbox',...
'Value',1,...
'Tag','pcumcheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'groupmeancheckbox';

h12 = uicontrol(...
'Parent',h9,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('groupmeancheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999998,...
'Position',[0.0423280423280423 0.528735632183908 0.941798941798942 0.241379310344828],...
'String','Plot Mean Grouped cycles ',...
'Style','checkbox',...
'Tag','groupmeancheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );

appdata = [];
appdata.lastValidTag = 'pexceedcheckbox';

h13 = uicontrol(...
'Parent',h9,...
'Units','normalized',...
'Callback',@(hObject,eventdata)fatChoice('pexceedcheckbox_Callback',hObject,eventdata,guidata(hObject)),...
'FontSize',9.99999999999998,...
'Position',[0.0423280423280423 0.0689655172413793 0.925925925925926 0.195402298850575],...
'String','Plot Prob. of Exceedance',...
'Style','checkbox',...
'Value',1,...
'Tag','pexceedcheckbox',...
'CreateFcn', {@local_CreateFcn, blanks(0), appdata} );


hsingleton = h1;


% --- Set application data first then calling the CreateFcn. 
function local_CreateFcn(hObject, eventdata, createfcn, appdata)

if ~isempty(appdata)
   names = fieldnames(appdata);
   for i=1:length(names)
       name = char(names(i));
       setappdata(hObject, name, getfield(appdata,name));
   end
end

if ~isempty(createfcn)
   if isa(createfcn,'function_handle')
       createfcn(hObject, eventdata);
   else
       eval(createfcn);
   end
end


% --- Handles default GUIDE GUI creation and callback dispatch
function varargout = gui_mainfcn(gui_State, varargin)

gui_StateFields =  {'gui_Name'
    'gui_Singleton'
    'gui_OpeningFcn'
    'gui_OutputFcn'
    'gui_LayoutFcn'
    'gui_Callback'};
gui_Mfile = '';
for i=1:length(gui_StateFields)
    if ~isfield(gui_State, gui_StateFields{i})
        error(message('MATLAB:guide:StateFieldNotFound', gui_StateFields{ i }, gui_Mfile));
    elseif isequal(gui_StateFields{i}, 'gui_Name')
        gui_Mfile = [gui_State.(gui_StateFields{i}), '.m'];
    end
end

numargin = length(varargin);

if numargin == 0
    % FATCHOICE
    % create the GUI only if we are not in the process of loading it
    % already
    gui_Create = true;
elseif local_isInvokeActiveXCallback(gui_State, varargin{:})
    % FATCHOICE(ACTIVEX,...)
    vin{1} = gui_State.gui_Name;
    vin{2} = [get(varargin{1}.Peer, 'Tag'), '_', varargin{end}];
    vin{3} = varargin{1};
    vin{4} = varargin{end-1};
    vin{5} = guidata(varargin{1}.Peer);
    feval(vin{:});
    return;
elseif local_isInvokeHGCallback(gui_State, varargin{:})
    % FATCHOICE('CALLBACK',hObject,eventData,handles,...)
    gui_Create = false;
else
    % FATCHOICE(...)
    % create the GUI and hand varargin to the openingfcn
    gui_Create = true;
end

if ~gui_Create
    % In design time, we need to mark all components possibly created in
    % the coming callback evaluation as non-serializable. This way, they
    % will not be brought into GUIDE and not be saved in the figure file
    % when running/saving the GUI from GUIDE.
    designEval = false;
    if (numargin>1 && ishghandle(varargin{2}))
        fig = varargin{2};
        while ~isempty(fig) && ~ishghandle(fig,'figure')
            fig = get(fig,'parent');
        end
        
        designEval = isappdata(0,'CreatingGUIDEFigure') || isprop(fig,'__GUIDEFigure');
    end
        
    if designEval
        beforeChildren = findall(fig);
    end
    
    % evaluate the callback now
    varargin{1} = gui_State.gui_Callback;
    if nargout
        [varargout{1:nargout}] = feval(varargin{:});
    else       
        feval(varargin{:});
    end
    
    % Set serializable of objects created in the above callback to off in
    % design time. Need to check whether figure handle is still valid in
    % case the figure is deleted during the callback dispatching.
    if designEval && ishghandle(fig)
        set(setdiff(findall(fig),beforeChildren), 'Serializable','off');
    end
else
    if gui_State.gui_Singleton
        gui_SingletonOpt = 'reuse';
    else
        gui_SingletonOpt = 'new';
    end

    % Check user passing 'visible' P/V pair first so that its value can be
    % used by oepnfig to prevent flickering
    gui_Visible = 'auto';
    gui_VisibleInput = '';
    for index=1:2:length(varargin)
        if length(varargin) == index || ~ischar(varargin{index})
            break;
        end

        % Recognize 'visible' P/V pair
        len1 = min(length('visible'),length(varargin{index}));
        len2 = min(length('off'),length(varargin{index+1}));
        if ischar(varargin{index+1}) && strncmpi(varargin{index},'visible',len1) && len2 > 1
            if strncmpi(varargin{index+1},'off',len2)
                gui_Visible = 'invisible';
                gui_VisibleInput = 'off';
            elseif strncmpi(varargin{index+1},'on',len2)
                gui_Visible = 'visible';
                gui_VisibleInput = 'on';
            end
        end
    end
    
    % Open fig file with stored settings.  Note: This executes all component
    % specific CreateFunctions with an empty HANDLES structure.

    
    % Do feval on layout code in m-file if it exists
    gui_Exported = ~isempty(gui_State.gui_LayoutFcn);
    % this application data is used to indicate the running mode of a GUIDE
    % GUI to distinguish it from the design mode of the GUI in GUIDE. it is
    % only used by actxproxy at this time.   
    setappdata(0,genvarname(['OpenGuiWhenRunning_', gui_State.gui_Name]),1);
    if gui_Exported
        gui_hFigure = feval(gui_State.gui_LayoutFcn, gui_SingletonOpt);

        % make figure invisible here so that the visibility of figure is
        % consistent in OpeningFcn in the exported GUI case
        if isempty(gui_VisibleInput)
            gui_VisibleInput = get(gui_hFigure,'Visible');
        end
        set(gui_hFigure,'Visible','off')

        % openfig (called by local_openfig below) does this for guis without
        % the LayoutFcn. Be sure to do it here so guis show up on screen.
        movegui(gui_hFigure,'onscreen');
    else
        gui_hFigure = local_openfig(gui_State.gui_Name, gui_SingletonOpt, gui_Visible);
        % If the figure has InGUIInitialization it was not completely created
        % on the last pass.  Delete this handle and try again.
        if isappdata(gui_hFigure, 'InGUIInitialization')
            delete(gui_hFigure);
            gui_hFigure = local_openfig(gui_State.gui_Name, gui_SingletonOpt, gui_Visible);
        end
    end
    if isappdata(0, genvarname(['OpenGuiWhenRunning_', gui_State.gui_Name]))
        rmappdata(0,genvarname(['OpenGuiWhenRunning_', gui_State.gui_Name]));
    end

    % Set flag to indicate starting GUI initialization
    setappdata(gui_hFigure,'InGUIInitialization',1);

    % Fetch GUIDE Application options
    gui_Options = getappdata(gui_hFigure,'GUIDEOptions');
    % Singleton setting in the GUI M-file takes priority if different
    gui_Options.singleton = gui_State.gui_Singleton;

    if ~isappdata(gui_hFigure,'GUIOnScreen')
        % Adjust background color
        if gui_Options.syscolorfig
            set(gui_hFigure,'Color', get(0,'DefaultUicontrolBackgroundColor'));
        end

        % Generate HANDLES structure and store with GUIDATA. If there is
        % user set GUI data already, keep that also.
        data = guidata(gui_hFigure);
        handles = guihandles(gui_hFigure);
        if ~isempty(handles)
            if isempty(data)
                data = handles;
            else
                names = fieldnames(handles);
                for k=1:length(names)
                    data.(char(names(k)))=handles.(char(names(k)));
                end
            end
        end
        guidata(gui_hFigure, data);
    end

    % Apply input P/V pairs other than 'visible'
    for index=1:2:length(varargin)
        if length(varargin) == index || ~ischar(varargin{index})
            break;
        end

        len1 = min(length('visible'),length(varargin{index}));
        if ~strncmpi(varargin{index},'visible',len1)
            try set(gui_hFigure, varargin{index}, varargin{index+1}), catch break, end
        end
    end

    % If handle visibility is set to 'callback', turn it on until finished
    % with OpeningFcn
    gui_HandleVisibility = get(gui_hFigure,'HandleVisibility');
    if strcmp(gui_HandleVisibility, 'callback')
        set(gui_hFigure,'HandleVisibility', 'on');
    end

    feval(gui_State.gui_OpeningFcn, gui_hFigure, [], guidata(gui_hFigure), varargin{:});

    if isscalar(gui_hFigure) && ishghandle(gui_hFigure)
        % Handle the default callbacks of predefined toolbar tools in this
        % GUI, if any
        guidemfile('restoreToolbarToolPredefinedCallback',gui_hFigure); 
        
        % Update handle visibility
        set(gui_hFigure,'HandleVisibility', gui_HandleVisibility);

        % Call openfig again to pick up the saved visibility or apply the
        % one passed in from the P/V pairs
        if ~gui_Exported
            gui_hFigure = local_openfig(gui_State.gui_Name, 'reuse',gui_Visible);
        elseif ~isempty(gui_VisibleInput)
            set(gui_hFigure,'Visible',gui_VisibleInput);
        end
        if strcmpi(get(gui_hFigure, 'Visible'), 'on')
            figure(gui_hFigure);
            
            if gui_Options.singleton
                setappdata(gui_hFigure,'GUIOnScreen', 1);
            end
        end

        % Done with GUI initialization
        if isappdata(gui_hFigure,'InGUIInitialization')
            rmappdata(gui_hFigure,'InGUIInitialization');
        end

        % If handle visibility is set to 'callback', turn it on until
        % finished with OutputFcn
        gui_HandleVisibility = get(gui_hFigure,'HandleVisibility');
        if strcmp(gui_HandleVisibility, 'callback')
            set(gui_hFigure,'HandleVisibility', 'on');
        end
        gui_Handles = guidata(gui_hFigure);
    else
        gui_Handles = [];
    end

    if nargout
        [varargout{1:nargout}] = feval(gui_State.gui_OutputFcn, gui_hFigure, [], gui_Handles);
    else
        feval(gui_State.gui_OutputFcn, gui_hFigure, [], gui_Handles);
    end

    if isscalar(gui_hFigure) && ishghandle(gui_hFigure)
        set(gui_hFigure,'HandleVisibility', gui_HandleVisibility);
    end
end

function gui_hFigure = local_openfig(name, singleton, visible)

% openfig with three arguments was new from R13. Try to call that first, if
% failed, try the old openfig.
if nargin('openfig') == 2
    % OPENFIG did not accept 3rd input argument until R13,
    % toggle default figure visible to prevent the figure
    % from showing up too soon.
    gui_OldDefaultVisible = get(0,'defaultFigureVisible');
    set(0,'defaultFigureVisible','off');
    gui_hFigure = openfig(name, singleton);
    set(0,'defaultFigureVisible',gui_OldDefaultVisible);
else
    gui_hFigure = openfig(name, singleton, visible);  
    %workaround for CreateFcn not called to create ActiveX
    if feature('HGUsingMATLABClasses')
        peers=findobj(findall(allchild(gui_hFigure)),'type','uicontrol','style','text');    
        for i=1:length(peers)
            if isappdata(peers(i),'Control')
                actxproxy(peers(i));
            end            
        end
    end
end

function result = local_isInvokeActiveXCallback(gui_State, varargin)

try
    result = ispc && iscom(varargin{1}) ...
             && isequal(varargin{1},gcbo);
catch
    result = false;
end

function result = local_isInvokeHGCallback(gui_State, varargin)

try
    fhandle = functions(gui_State.gui_Callback);
    result = ~isempty(findstr(gui_State.gui_Name,fhandle.file)) || ...
             (ischar(varargin{1}) ...
             && isequal(ishghandle(varargin{2}), 1) ...
             && (~isempty(strfind(varargin{1},[get(varargin{2}, 'Tag'), '_'])) || ...
                ~isempty(strfind(varargin{1}, '_CreateFcn'))) );
catch
    result = false;
end


