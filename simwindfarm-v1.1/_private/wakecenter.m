%Cumputes the wake center from p until farm end
function wc=wakecenter(uy,p,offset)
    %computer number of grid points from px
    it=ceil((p.grid.xsize-p.wt.x)/p.grid.size);
    %Turbine intial rolling grid position
    g=p.grid.xgrids-ceil(p.wt.x/p.grid.size); 
    %j = grid distance to wc for time offset-j
    for j=1:it
        t=offset-j+g;
        %Must compute it number of wake centerrs
        c=p.wt.y; %wake center starts at turbine position
        %Check for time
        if (t>0)
            for i=1:j %Compute the meandering for time interval 1 to j
                uysum=0;
                %compute the grid number for low meandering edge
                m_min=max(floor((c-p.wt.meand.r(i))/p.grid.size)+1,1); 
                %compute the grid number for the high meandering edge
                m_max=min(floor((c+p.wt.meand.r(i))/p.grid.size)+1,size(uy,1)); 

                %average transversal velocity over the wake area
                for y=m_min:m_max
                    uysum=uysum+uy(y,t);
                end
                uyavg=uysum/(m_max-m_min+1);

                % wake center filtered
                % Should be calculated from mean air speed vs uyavg and lowpass filtered
                % Redo filter computation
                % yeff=ts*uyavg=grid.size/uxmean*uyavg
                % wc=wc+alpha*uyavg

                %Uncomment to reproduce bug
                %wc=p.wt.y;

                %Uncomment to reproduce meandering limits
                %wc=min(max(wc,p.wt.y-150),p.wt.y+150);

                %Notice here ts such that wake moves with uyavg speed
                c=c+p.ts*uyavg;
                %Make sure it stays in bounds
            end
        else %Before creation
            c=1;
        end
        wc(j)=max(min(c,p.grid.ysize),1);
    end
end