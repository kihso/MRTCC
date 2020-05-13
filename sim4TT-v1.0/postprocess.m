function [xdotdot,xdot,x,F] = postprocess(Y,U,A,B,Ms,Ks,Cs,NDOF)

x=Y(1:NDOF,:);
xdot=Y(NDOF+1:NDOF*2,:);

xdotdot=A*Y+B*U;
xdotdot=xdotdot(NDOF+1:end,:);

F=Ms*xdotdot+Ks*x+Cs*xdot;

end