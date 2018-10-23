function compat=iscompat(v)

%Not checking at all, before fix is in
%compat=true;
%return ;

%Now checking for exact version
create_windfarm_paths = which('create_windfarm','-all');
if(isunix)
    create_windfarm_paths = create_windfarm_paths{end}(2:(end-18));
elseif(ispc)
    create_windfarm_paths = create_windfarm_paths{end}(4:(end-18));
end
    
try
    tbinf=ver(create_windfarm_paths);
    cver=tbinf.Version;
    compat=strcmp(v,cver);
catch me
    compat=false;
end


end