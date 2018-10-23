function [Cp F beta tsr omega] = processWT_Perf_file(filename)
%% [Cp F beta tsr omega] = processWT_Perf_file(filename)
%This function reads the cp and ct table directly from the output files
%from WT_Perf. It does that by searching for the string '(deg)', which
%signifies the beginning of the table. It assumes that both the Cp and Ct
%table are in the same file.
%
% Created by Mikael Svenstrup - Aalborg University 


%open file
fid = fopen(filename);


%Find Cp
findTableStart();
%The rest of the column is the tip speed ratio
tsr = textscan(fid,'%s', 1 ,'delimiter','\n');
tsr = str2num(tsr{1}{1});

%Read the rest of the table
strFormat = ['%f' repmat('%f',1,length(tsr))];
data = cell2mat(textscan(fid,strFormat));
beta = data(:,1);
Cp = data(:,2:end);


%Then find Ct
findTableStart();
%The rest of the column is the tip speed ratio
tsr = textscan(fid,'%s', 1 ,'delimiter','\n');
tsr = str2num(tsr{1}{1});

%Read the rest of the table
strFormat = ['%f' repmat('%f',1,length(tsr))];
data = cell2mat(textscan(fid,strFormat));
beta = data(:,1);
F = data(:,2:end);





    function  findTableStart()
        
        unit = cell(1);
        %Scan through the file until we find the rotational speed
        omega = cell(1);
        while(~strcmp(omega{1},'Omega'))
            omega = textscan(fid,'%s', 1 ,'delimiter',' ');
        end
        %Obtain rotational speed
        omega = textscan(fid,'%s%f%s', 1 ,'delimiter',' ');
        omega = cell2mat(omega(2))/60*2*pi;
        
        %Find out where the table starts, it starts with a '(deg)' in first column
        unit = cell(1);
        while(~strcmp(unit{1},'(deg)'))
            unit = textscan(fid,'%s', 1 ,'delimiter',' ');
        end
        
    end

end

