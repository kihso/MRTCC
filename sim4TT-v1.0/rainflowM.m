function [dS,Sm] = rainflowM(S)
% Rainflow cycle counting algorithm from  
% Amzallag et al. "Standardization of the rainflow counting method 
% for fatigue analysis", Int. J. Fatigue, 16, pp. 287-293, 1993.
%
% input:    S   = stress/load signal (column vector)
%
% outputs:  dS  = vector of stress ranges
%           Sm  = vector of mean stress
%           size of both vectors: [nx1], where n is number of cycles (not binned)
%
% ALGORITHM:
% - read in 4 successive points, S1, S2, S3 and S4
% - calculate 3 possible ranges from those, dS1, dS2 and dS3
% - if dS2 is smaller than the neighbours it is extracted and S2+S3 deleted
% - the remaining parts are joined and the process repeats
% - residual cycles are treated by duplicating the signal and re-running
%   then algorithm, thus closing all cycles.
%
%
%  by M.M. Pedersen, Aarhus University, 2017.
%


    % break if signal is flat - then no cycles can be found
    if max(S) == min(S) || length(S)<3
        error('Signal does not contain any cycles.');
    end

    % check that S is column vector
    if ~(size(S,1)>1)
        error('S must be a column vector.');
    end
    
    
    
    % take care of potential repeated values
    S = fix_repeated_values(S);
    
    % reduce signal to list of extrema
    S = sig2ext(S);

    
    
    % initialize output arrays 
    n = length(S);
    dS = zeros(n,1);
    Sm = zeros(n,1);
    c = 1;

    % run twice (second run to treat residue)
    for m = 1:2

        i = 1;
        j = 1;

        while ~(i+3>length(S))

            % read in 4 successive points
            S1 = S(i);
            S2 = S(i+1);
            S3 = S(i+2);
            S4 = S(i+3);

            % calculate range of those
            dS1 = abs(S2-S1);
            dS2 = abs(S3-S2);
            dS3 = abs(S4-S3);

            % extract center range, if smaller than or equal to both neighbouring ranges
            if dS2 <= dS1 && dS2 <= dS3

                % store cycle
                dS(c) = dS2;
                Sm(c) = (S2 + S3)/2;
                c = c+1;

                % joining signal
                for k = i+2:-1:j+2
                    S(k) = S(k-2);
                end

                j = j+2;
                i = j;

            else
                i = i+1;
            end

        end

        % duplicate residual signal and run again
        res = S(j:end);
        
        if length(res)<3 % residue contains no cycles
           break
        end
        
        % make sure that signal is joined correctly
        if res(1)==res(end)
            S = [res(1:end-1); res];
        else
            S = [res; res];
            S = sig2ext(S);
        end

    end

    % remove unused array entries
    dS(c:end) = [];
    Sm(c:end) = [];
    
end



function Se = sig2ext(S)
% extract list of extrema from signal S

    n_steps = size(S,1);
    Se = zeros(n_steps,1);
    Se(1) = S(1);
    j = 1;

    for i = 2:(n_steps-1)

        if (S(i)>S(i-1) && S(i)>S(i+1)) ...
        || (S(i)<S(i-1) && S(i)<S(i+1)) ...

            j = j+1;
            Se(j) = S(i);

        end;

    end;

    % keep last entry
    Se(j+1) = S(end);

    % remove unused entries
    Se(j+2:end) = [];
    
end


function S = fix_repeated_values(S)
% check signal for repeated values and fix if any found.

    n = length(S);

    % in case of repeated values, scale one of them a little 
    for i = 1:n-1
        if S(i)==S(i+1)
            S(i+1) = S(i+1)*0.99999;
        end
    end

end