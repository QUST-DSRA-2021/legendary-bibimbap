package io.github.sandyzikun.grph;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Square extends JFrame implements ActionListener {
    int FRAME_WIDTH = 960;
    int FRAME_HEIGHT = FRAME_WIDTH * 9 / 16;
    int CENTER_X = FRAME_WIDTH / 2,
        CENTER_Y = FRAME_HEIGHT / 2;
    JButton [] dirbtn = {
        new JButton("Move Left"),
        new JButton("Move Down"),
        new JButton("Move Up"),
        new JButton("Move Right"),
    };
    Panel mainpnl = new Panel(new FlowLayout());
    private class SquareMovingCanvas extends Canvas {
        int WIDTH = 30,
                HEIGHT = 30,
                STEP = 10,
                k, l;
        public void paint(Graphics g) {
            g.drawRect(0, 0, this.getSize().width - 1, this.getSize().height - 1);
            g.setColor(new Color(0, 43, 54));
            g.fillRect(k + 2, l + 2, WIDTH + 2, HEIGHT + 2);
            g.setColor(new Color(220, 50, 47));
            g.fillRect(k, l, WIDTH, HEIGHT);
        } public void move_left() {
            k = (k > 0) ? (k - STEP) : (this.getSize().width - STEP);
            repaint();
        } public void move_down() {
            l = (l < this.getSize().height - STEP) ? (l + STEP) : 0;
            repaint();
        } public void move_up() {
            l = (l > 0) ? (l - STEP) : (this.getSize().height - STEP);
            repaint();
        } public void move_right() {
            k = (k < this.getSize().width - STEP) ? (k + STEP) : 0;
            repaint();
        }
    }
    SquareMovingCanvas drawcvs = new SquareMovingCanvas();
    private class WindowCloser extends WindowAdapter {
        public void windowClosing(WindowEvent e) {
            System.exit(0);
        }
    }
    void layout_generate() {
        this.setLayout(new BorderLayout());
        this.add(mainpnl, BorderLayout.SOUTH);
        this.add(drawcvs, BorderLayout.CENTER);
        for (int k = 0; k != dirbtn.length; ++k)
            mainpnl.add(dirbtn[k]);
        this.validate();
        for (int k = 0; k != dirbtn.length; ++k)
            dirbtn[k].addActionListener(this);
        this.addWindowListener(new WindowCloser());
    }
    public Square() {
        super("Square Moving");
        this.setSize(FRAME_WIDTH, FRAME_HEIGHT);
        this.setDefaultCloseOperation(3);
        this.setLocationRelativeTo(null);
        layout_generate();
    }
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == dirbtn[0])
            drawcvs.move_left();
        else if (e.getSource() == dirbtn[1])
            drawcvs.move_down();
        else if (e.getSource() == dirbtn[2])
            drawcvs.move_up();
        else if (e.getSource() == dirbtn[3])
            drawcvs.move_right();
        else
            return;
    }
}
