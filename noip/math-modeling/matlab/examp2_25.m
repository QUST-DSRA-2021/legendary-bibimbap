t=0:.2:2*pi; y=sin(t);  % �����ɻ�ͼ������
subplot(2,2,1), stairs(t,y)  % �ָ�ڣ������Ͻǻ��ƽ�������
subplot(2,2,2), stem(t,y)  % �������߻���
subplot(2,2,3), bar(t,y)  % ֱ��ͼ����
subplot(2,2,4), semilogx(t,y)  % ������Ϊ����������
