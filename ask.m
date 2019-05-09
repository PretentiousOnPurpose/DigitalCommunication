clc;
clear all;
close all;
t = 0:0.005:4;
c = sin(2 * pi * 10 * t);
m = square(2 * pi * t);
m(m <= 0) = 0;

s = m .* c;

b_ = s .* c;

b_ = filter(ones(1, 5), 1, b_);

b_(b_ > 0) = 1;

subplot(2, 1, 1);
plot(m);
subplot(2, 1, 2);
plot(b_);
