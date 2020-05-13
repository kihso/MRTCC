%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Make damping matrix by assining a damping ratio to each mode
% 
% Input, system mass matrix, M, stiffness matrix, K and zeta containing
% damping ratios in procentages ! 
% 
% Output, damping matrix (NOT MODAL DAMPING MATRIX)
%
% Oliver Tierdad Filsoof, Copyright Vestas Wind System A/S
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
function C = ModalDamping(M,K,zeta)

% Change zeta from procent
zeta=zeta/100;

% Eigenvalue analysis
[V,D]=eig(K,M);
% Sort eigenvalues and eigenvectors to proper assign damping 
% efficients to each mode
[D,Index]=sort(diag(D));
V=V(:,Index);
eig_freq=real(sqrt(D)); % Natural frequency in rad/s

N=length(zeta);

% Calculate diagonal matrix of generalized modal masses
V = V * diag(sqrt( diag(V'*(M*V)).^(-1) ) );
Mq = V'*M*V;

% Caluclate damping matrix as a summation
C = zeros(size(Mq));
for i=1:N
    Ctemp =( 2*zeta(i)*eig_freq(i)/Mq(i,i)*V(:,i)*V(:,i)' );
    C = C + Ctemp; 
end

C=M*C*M;