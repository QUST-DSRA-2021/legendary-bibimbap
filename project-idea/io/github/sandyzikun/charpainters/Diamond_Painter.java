package io.github.sandyzikun.charpainters;

public class Diamond_Painter extends Charpainter {
    public Diamond_Painter() {
        super();
    }

    public Diamond_Painter(int num_lines) {
        super(num_lines);
    }

    public void charpaint() {
        for (int k = 0; k != m_lns; ++k) {
            for (int l = 0; l != m_lns - k - 1; ++l)
                System.out.print(' ');
            for (int l = 0; l != 2 * k + 1; ++l)
                System.out.print('*');
            System.out.print('\n');
        }
        for (int k = 0; k != m_lns - 1; ++k) {
            for (int l = 0; l != k + 1; ++l)
                System.out.print(' ');
            for (int l = 0; l != 2 * (m_lns - k) - 3; ++l)
                System.out.print('*');
            System.out.print('\n');
        }
    }
}
