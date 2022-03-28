package io.github.sandyzikun.charpainters;

public class Revmired_Tripainter extends Charpainter {
    public Revmired_Tripainter() {
        super();
    }

    public Revmired_Tripainter(int num_lines) {
        super(num_lines);
    }

    public void charpaint() {
        for (int k = 0; k != m_lns; ++k) {
            for (int l = 0; l != k; ++l)
                System.out.print(' ');
            for (int l = 0; l != m_lns - k; ++l)
                System.out.print('*');
            System.out.print('\n');
        }
    }
}
