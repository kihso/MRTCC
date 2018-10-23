%calculate deficit at timstep offset
function a=deficit(CT,p,offset)
    a=ones(1,p.grid.xgrids);
    it=ceil((p.grid.xsize-p.wt.x)/p.grid.size);
    %Min makes sure not to exceed CT history
    for i=1:min(it,offset-1);
        px=p.grid.size*i;
        %wake deficit at px-wtx distance from turbine
        a(i+p.grid.xgrids-it)=1-.5*CT(offset-i)/(1+(px)/(4*p.wt.rotor.r));
    end
end

