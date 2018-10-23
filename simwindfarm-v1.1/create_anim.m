function create_anim(sys,logs)
%makes it possible to create movies.


go=questdlg('Save the animation as a movie?','Wind field animation','Yes','No',{'No'});
%Go forward?
switch(go)
    case 'Yes'
        config.movie.go=true;
    otherwise
        config.movie.go=false;
end

if(config.movie.go)
    
    [file,path]=uiputfile('*.avi','Save Wind Field Animation As','windanim.avi');

    if isequal(file,0) || isequal(path,0)
        config.movie.go=false;
    else
        config.movie.name=[path file];
    end
    
    % jdg to mkr: You might add an isunix thing in order to enable compression
    % on windows 
    %Get frame rate and compression
    options.Resie='off';
    options.WindowStyle='normal';
    options.Interpreter='none';
    qs={'Frames per second', ...
                'Compression'};
    answer={'15','None'};
    animparm=inputdlg(qs,'Wind Animation',1,answer,options);
    
    if (isempty(animparm))
        config.movie.go=false;
    else
        config.movie.fps=str2num(animparm{1});
        config.movie.compress=animparm{2};
    end
end

    windanim(sys,logs,config)
end


