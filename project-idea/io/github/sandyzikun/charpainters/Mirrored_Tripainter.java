package io.github.sandyzikun.charpainters;

public class Mirrored_Tripainter extends Charpainter {
    public Mirrored_Tripainter() {
        super();
    }

    public Mirrored_Tripainter(int num_lines) {
        super(num_lines);
    }

    public void charpaint() {
        for (int k = 0; k != m_lns; ++k) {
            for (int l = 0; l != m_lns - k - 1; ++l)
                System.out.print(' ');
            for (int l = 0; l != k + 1; ++l)
                System.out.print('*');
            System.out.print('\n');
        }
    }
}
