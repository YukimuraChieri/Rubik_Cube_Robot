clear; clc;
close all;

% �������S���߼Ӽ������߻���

t = 0:0.001:1;                      % ����ʱ������
st = [0.2, 0.4, 0.6, 0.8, 1.0];     % ʱ��׶�
Amax = 5;                           % �����ٶ�

a = A_curve(Amax, st, t);

v = zeros(1, length(t));

for n = 2:length(t)-1
    v(n) = trapz([0, 0.001], [a(n),a(n+1)]) + v(n-1);
end

subplot(211);
plot(t, a);
title('���ٶ�����');
ylabel('���ٶȣ�r/s^2��');
xlabel('ʱ�䣨s��');
grid on;
subplot(212);
plot(t, v);
title('�ٶ�����');
ylabel('�ٶȣ�r/s��');
xlabel('ʱ�䣨s��');
grid on;


%% ���ٶ����ߺ���
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





