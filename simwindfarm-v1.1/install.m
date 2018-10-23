function install()
%Installs the toolbox in the Matlab path. The path-file must be writeable
%for the install to be persistent across Matlab sessions.

create_windfarm_paths = which('create_windfarm','-all');

if((size(create_windfarm_paths,1) > 1))
    fprintf(2,'Warning: Another version of the toolbox is already installed. Please uninstall it first.\n');
    cnt=input('Continue installation anyway? Y/N [N]: ','s');
    if(~strcmpi(cnt,'Y'))
        return
    end
end

p=pwd();
addpath(p);
addpath([p '/mcrunch']);
if(savepath())
    fprintf(2,'Warning: The path could not be saved, probably caused by lack of permissions.\n The toolbox should work for this session but the install needs to be run on the next startup of Matlab.\n');
end
disp('SimWindFarm Toolbox Installed');
end