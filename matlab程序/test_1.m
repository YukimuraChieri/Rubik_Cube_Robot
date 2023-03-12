clear; clc;
close all;

% 步进电机S曲线加减速曲线绘制

t = 0:0.001:1;                      % 抽样时间序列
st = [0.2, 0.4, 0.6, 0.8, 1.0];     % 时间阶段
Amax = 5;                           % 最大加速度

a = A_curve(Amax, st, t);

v = zeros(1, length(t));

for n = 2:length(t)-1
    v(n) = trapz([0, 0.001], [a(n),a(n+1)]) + v(n-1);
end

subplot(211);
plot(t, a);
title('加速度曲线');
ylabel('加速度（r/s^2）');
xlabel('时间（s）');
grid on;
subplot(212);
plot(t, v);
title('速度曲线');
ylabel('速度（r/s）');
xlabel('时间（s）');
grid on;


%% 加速度曲线函数
function data = A_curve(Amax, st, t)
    k = Amax/st(1);
    
    data = zeros(1, length(t));
    n = 1;
    
    for tn = t
        if tn <= st(1)
            data(n) = k*tn;
        elseif tn <= st(2)
            data(n) = -k*(tn-st(1))+Amax;
        elseif tn <= st(3)
            data(n) = 0;
        elseif tn <= st(4)
            data(n) = -k*(tn-st(3));
        elseif tn <= st(5)
            data(n) = k*(tn-st(4))-Amax;
        end
        n = n + 1;
    end
end





