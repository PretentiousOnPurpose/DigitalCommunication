clc;
clear all;
close all;
N = 256

t = linspace(0, 16 * pi, 4096);
a1 = sin(4 * t);
b = square(0.5 * t);
b(b <= 0) = 0;

y(1:N) = zeros(1, N);

for i=N+1:N:length(b)
    y(i:i+N-1) = xor(b(i:i+N-1), y(i-N:i-1));
end

y(y == 0) = -1;
s = y .* a1;

z(1:N) = s(1:N);
for i=N+1:N:length(b)
    z(i:i+N-1) = s(i:i+N-1) .* s(i-N:i-1);
end

d = filter(ones(1, 5), 1, z);
d(d > 0) = 0;
d(d < 0) = 1;


subplot(2, 1, 1);
plot(b);
subplot(2, 1, 2);
plot(d);
