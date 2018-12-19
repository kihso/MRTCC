function DEL = DEL_fun(S,Nbin,Neq,m)
% Rainflow counting
[dS,~]=rainflowM(S);
% Bin data
[N,edges]=histcounts(dS,Nbin);
edges=edges(2:end);
% plot(edges,N)
% DEL
DEL=(sum(edges.*N)/Neq)^(1/m);
end