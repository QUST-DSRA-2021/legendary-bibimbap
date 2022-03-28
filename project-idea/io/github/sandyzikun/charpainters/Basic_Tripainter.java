package io.github.sandyzikun.charpainters;

public class Basic_Tripainter extends Charpainter {
    public Basic_Tripainter() {
        super();
    }

    public Basic_Tripainter(int num_lines) {
        super(num_lines);
    }

    public void charpaint() {
        for (int k = 0; k != m_lns; ++k) {
            for (int l = 0; l != k + 1; ++l)
                System.out.print('*');
            System.out.print('\n');
        }
    }
}
