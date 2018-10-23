function [cp ct] = fix_cp_table(cp,plot_cp,ct,beta,tsr)
%% [cp ct] = fix_cp_table(cp,plot_cp,ct,beta,tsr)
% There are some holes in the cp and table, where WTPerf did not converge
% Fortunately all those places, the value of the cp table is exactly
% -9.9999 (the ct table does not have a fixed wrong value, however it is
% the same places as with the Cp table). This value is subject to the
% setting in the WT_Perf configuration file
% In this script this is corrected by interpolating from points around
% If a ct table is provided as the third argument, the values at the same
% indices as with the cp table are fixed
% This function does not handle the places where it is not possible to
% interpolate using either the x-axis direction or the y-axis direction.
% For example if cp(xi,yi), cp(xi+1,yi),cp(xi,yi+1) are affected, then
% cp(xi,yi) will not be corrected - however the other two will!
% if plot_cp == true, then the new and old cp surface is plotted for
% comparison. You can specify beta and tsr for this plot. Otherwise these
% two input are not needed.
%
% Created by Mikael Svenstrup - Aalborg University 


if(nargin == 1)
    plot_cp = false;
end

if(nargin >= 3)
    fix_ct = true;
else
    fix_ct = false;
    ct = 0;
end



cp_old = cp;

%Find the indices of the affected points:
[I J] = find(cp==-9.9999);

%Find out if there are any places with points with manhattan distances
%equal to 1. If so, the interpolation could go wrong:

for ii = 1:length(I)
    vals= []; %Values around the given point
    vals_ct = [];
    
    
    d = find(abs(J(ii) - J)+abs(I(ii)-I)==1); %The manhattan distance to all points
    skip_x = false;
    skip_y = false;
    if(~isempty(d)) %If two points are beside each other, then do something else
        if(find(abs(I(ii) - I(d))==1)) %It is an x-axis problem
            skip_x = true;
        end
        if(find(abs(J(ii) - J(d))==1)) %It is a y-axis problem
            skip_y = true;
        end
        
        if(skip_x && skip_y) %if there is both a problem on the x and Y axis
            warning('There is a problem with interpolation because sourrounding points in both x and y direction are false - setting Cp curve to 0 at indices Cp(%d,%d)',I(ii),J(ii)    )
            vals = 0;
        end
        
    end
    
    
    
    %Find the sourrounding values on the x-xais
    if((I(ii) > 1) && I(ii) < size(cp,1)) %If values are on the edge, only take the numbers in the other direction
        if(~skip_x) %Check if there is a problem with the x-axis
            vals = [vals ; cp(I(ii)+[-1 1],J(ii))];
            if(fix_ct)
                vals_ct = [vals_ct ; ct(I(ii)+[-1 1],J(ii))];
            end
        end
    end
    
    %Find the sourrounding values on the y-axis
    if((J(ii) > 1) && J(ii) < size(cp,2)) %If values are on the edge, only take the numbers in the other direction
        if(~skip_y) %Check if there is a problem with the x-axis
            vals = [vals ; cp(I(ii),J(ii)+[-1 1])'];
            if(fix_ct)
                vals_ct = [vals_ct ; ct(I(ii),J(ii)+[-1 1])'];
            end
        end
    end
    
    cp(I(ii),J(ii)) = sum(vals(:))/length(vals(:)); %Take the average of the values around
    if(fix_ct)
        ct(I(ii),J(ii)) = sum(vals_ct(:))/length(vals_ct(:)); %Take the average of the values around
    end
    
end

if(plot_cp)
    %Create dummy values of tsr and beta if they are not given as input
    if(~exist('tsr') || ~exist('beta'))
        [beta , tsr] = size(cp);
        tsr = 1:tsr;
        beta = 1:beta;
    end
    
    figure
    contourf(tsr,beta,ct)
    title('Fixed Cp surface')
    figure
    contourf(tsr,beta,cp_old)
    title('Old Cp surface')
end