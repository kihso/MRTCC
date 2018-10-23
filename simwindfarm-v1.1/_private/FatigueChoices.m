function varargout = FatigueChoices(varargin)
% FATIGUECHOICES M-file for FatigueChoices.fig
%      FATIGUECHOICES, by itself, creates a new FATIGUECHOICES or raises the existing
%      singleton*.
%
%      H = FATIGUECHOICES returns the handle to a new FATIGUECHOICES or the handle to
%      the existing singleton*.
%
%      FATIGUECHOICES('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in FATIGUECHOICES.M with the given input arguments.
%
%      FATIGUECHOICES('Property','Value',...) creates a new FATIGUECHOICES or raises
%      the existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before FatigueChoices_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to FatigueChoices_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help FatigueChoices

% Last Modified by GUIDE v2.5 26-Jan-2010 13:45:29

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @FatigueChoices_OpeningFcn, ...
                   'gui_OutputFcn',  @FatigueChoices_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
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

% --- Executes just before FatigueChoices is made visible.
function FatigueChoices_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to FatigueChoices (see VARARGIN)

% Choose default command line output for FatigueChoices
handles.fighandle = hObject;
handles.choices={};

% Update handles structure
guidata(hObject, handles);



% UIWAIT makes FatigueChoices wait for user response (see UIRESUME)
uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = FatigueChoices_OutputFcn(hObject, eventdata, handles)
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
