clear; clc;
close all;

% 步进电机S曲线加减速脉冲周期序列生成2


PlusMax = 1000;  % 加速阶段最大脉冲数

V = zeros(1, PlusMax);
delta_V = zeros(1, PlusMax);
a = zeros(1, PlusMax);
t = zeros(1, PlusMax);
delta_t = zeros(1, PlusMax);

Amax = 10;      % 最大加速度(r/s^2)
st = 0.1;           % 加减速时间，单位：s
vt = 0.1;           % 匀速时间段

k = Amax/(st/2);

delta_t(1) = 0.01;  % 初始脉冲周期
V(1) = 1/(1000*delta_t(1));


for num = 2:PlusMax
    if t(num-1) < vt+2*st
        t(num) = t(num-1)+delta_t(num-1);
        V(num) = V_curve(t(num), st, vt, Amax);
        delta_t(num) = 1/(1000*V(num));
    else
        break;
    end
end

% t =linspace(0, st*2+vt, 5000);                      % 抽样时间序列
% 
% n=1;
% for tn = t
%     V(n) = V_curve(tn, st, vt, Amax);
%     n = n+1;
% end

subplot(211);
scatter(t(1:num-1), V(1:num-1), '.');
% plot(t, V);
grid on;
axis([0, vt+2*st, 0, Amax*st/2 + 0.2]);
title('速度曲线离散化');
ylabel('速度（r/s）');
xlabel('时间（s）');

subplot(212);
stem(t(1:num-1), 1000*delta_t(1:num-1), '.');
grid on;
axis([0, vt+2*st, 0, 12]);
title('脉冲周期时间');
ylabel('\Deltat周期(ms)');
xlabel('时间（s）');


% 输出各个脉冲周期的微秒数
for n = 1:num-1
    
	fprintf("%d,\t", vpa(delta_t(n)*1e6-1,2));
    
    if mod(n, 10) == 0
        fprintf("\n");
	end
end

fprintf("\n");

disp("%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");


%%
function vel = V_curve(t, st, vt, Amax)

    k = Amax/(st/2);
    v0 = 0.1;       % 初始转速（r/s）
    
    if t <= st/2
        vel = k*t^2/2+v0;
    elseif t <= st
        vel = Amax*(t-st/4) - (k*(t - st/2)^2)/2+v0;
    elseif t <= st+vt
        vel = Amax*(st/2)+v0;
    elseif t <= vt+3*st/2
        vel = -(k*(t - (st+vt))^2)/2+v0 + Amax*(st/2);
    elseif t <= vt+2*st
        vel = (k*(t - (vt+3*st/2))^2)/2 - Amax*(t-(vt+7*st/4)) + v0;
    else
        vel = v0;
    end
end



