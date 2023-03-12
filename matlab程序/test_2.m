clear; clc;
close all;

% �������S���߼Ӽ�������������������2


PlusMax = 1000;  % ���ٽ׶����������

V = zeros(1, PlusMax);
delta_V = zeros(1, PlusMax);
a = zeros(1, PlusMax);
t = zeros(1, PlusMax);
delta_t = zeros(1, PlusMax);

Amax = 10;      % �����ٶ�(r/s^2)
st = 0.1;           % �Ӽ���ʱ�䣬��λ��s
vt = 0.1;           % ����ʱ���

k = Amax/(st/2);

delta_t(1) = 0.01;  % ��ʼ��������
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

% t =linspace(0, st*2+vt, 5000);                      % ����ʱ������
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
title('�ٶ�������ɢ��');
ylabel('�ٶȣ�r/s��');
xlabel('ʱ�䣨s��');

subplot(212);
stem(t(1:num-1), 1000*delta_t(1:num-1), '.');
grid on;
axis([0, vt+2*st, 0, 12]);
title('��������ʱ��');
ylabel('\Deltat����(ms)');
xlabel('ʱ�䣨s��');


% ��������������ڵ�΢����
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
    v0 = 0.1;       % ��ʼת�٣�r/s��
    
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



