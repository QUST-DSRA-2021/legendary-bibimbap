package io.github.sandyzikun.charpainters;

public class Reversed_Tripainter extends Charpainter {
    public Reversed_Tripainter() {
        super();
    }

    public Reversed_Tripainter(int num_lines) {
        super(num_lines);
    }

    public void charpaint() {
        for (int k = 0; k != m_lns; ++k) {
            for (int l = 0; l != m_lns - k; ++l)
                System.out.print('*');
            System.out.print('\n');
        }
    }
}
