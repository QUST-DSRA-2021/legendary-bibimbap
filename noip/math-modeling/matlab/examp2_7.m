syms a b c d t; % ������Щ������Ϊ���ű���
f=cos(a*t+b)+sin(c*t)*sin(d*t);  % ����������� f(t)
f1=taylor(f);   % ���� taylor() ������ȡ Taylor չ��
latex(f1)  % �����ת���� LaTeX ���ʽ���������