[x,y]=meshgrid(0:31); n=2; D0=200;
D=sqrt((x-16).^2+(y-16).^2); z=1./(1+D.^(2*n)/D0); % �����˲���
subplot(221), surf(x,y,z), view(0,90); axis([0,31,0,31,0,1]); % ����ͼ
subplot(222), surf(x,y,z), view(90,0); axis([0,31,0,31,0,1]); % ����ͼ
subplot(223), surf(x,y,z), view(0,0); axis([0,31,0,31,0,1]);  % ����ͼ
subplot(224), surf(x,y,z), axis([0,31,0,31,0,1]); % ��άͼ
