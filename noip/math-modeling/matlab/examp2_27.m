t=0:.1:2*pi;   % ���� t ������ע������ĵ�����
x=t.^3.*sin(3*t).*exp(-t); y=t.^3.*cos(3*t).*exp(-t); z=t.^2;
plot3(x,y,z), grid  % ��ά���߻���

stem3(x,y,z); hold on; plot3(x,y,z), grid
