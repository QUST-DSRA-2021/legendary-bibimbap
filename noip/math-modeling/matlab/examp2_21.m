P=[1 2 4 0 5]; Q=[1 2]; F=[1 2 3]; D=convs(P,Q,F)

E=conv(conv(P,Q),F)  % ������ conv() ����������ҪǶ�׵���

G=convs(P,Q,F,[1,1],[1,3],[1,1])
      