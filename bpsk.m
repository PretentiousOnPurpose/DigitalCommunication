clc;
clear all;
close all;

t = 0:0.005:2;
m = (1 + square(2 * pi * 1 * t))/2;
c1 = sin(2 * pi * 10 * t);
c2 = sin(2 * pi * 10 * t + pi);

for i=1:401
    if (m(i) > 0)
        y(i) = c1(i);
    else
        y(i) = c2(i);
    end
end

a2 = y .* c1;
a = 1;
b = ones(1, 5);
a4 = filter(b, a, a2);
a5 = hardlims(a4);

plot(a5);
