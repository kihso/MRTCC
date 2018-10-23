function uninstall()

create_windfarm_paths = which('create_windfarm','-all');
if(isunix)
    create_windfarm_paths = create_windfarm_paths{end}(2:(end-18));
elseif(ispc)
    create_windfarm_paths = create_windfarm_paths{end}(4:(end-18));
else
    disp('Cannot uninstall the SimWindFarm Toolbox - Please remove paths manually')
end

if(isempty(ver(create_windfarm_paths)))
    fprintf(2,'Warning: Toolbox not installed.\n');
    return
end
%tbpath=fileparts(mfilename('fullpath'));
%rmpath(tbpath, [tbpath '/mcrunch']);
if(isunix)
    tbpath=['/' create_windfarm_paths];
    rmpath(tbpath, [tbpath '/mcrunch']);
elseif(ispc)
    create_windfarm_paths = which('create_windfarm','-all');
    create_windfarm_paths = create_windfarm_paths{end}(1:(end-18));
    rmpath(create_windfarm_paths,[create_windfarm_paths '/mcrunch']);
end
if(savepath())
    fprintf(2,'Warning: The path could not be saved, probably caused by lack of permissions.\n The toolbox should be uninstalled for this session but the uninstall might need to be rerun on the next startup of Matlab.\n');
else
    disp('SimWindFarm Toolbox Unstalled');

end
end