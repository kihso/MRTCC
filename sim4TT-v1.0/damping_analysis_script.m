% Evalaute damping of the different states in the A matrix
D = eig(A_4TT); % Find the eigen values of the A matrix
frq = imag(D)/(2*pi); % Find the frequencies of the A matrix
damp = -100*real(D)./abs(D); % Find the damping levels of each eigenvalue (-100 is just convert to procentage) "Convert to log dec by multiplying with 2pi"
[frq_sorted,frq_sorted_idx]=sort(frq); % Sorting based on the frequency
damp_sorted = damp(frq_sorted_idx);