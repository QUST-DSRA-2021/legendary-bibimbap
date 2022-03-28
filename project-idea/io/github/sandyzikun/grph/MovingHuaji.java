package io.github.sandyzikun.grph;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class MovingHuaji extends JFrame implements ActionListener {
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
        int RADIUS_CIRCLE = 216,
            RADIUS_MOUTH = 192,
            RADIUS_EYE = 15;
        int CENTER_X = FRAME_WIDTH / 2,
            CENTER_Y = FRAME_HEIGHT / 2;
        void draw_arc_withrect(Graphics g,
                               int x, int y,
                               int width, int height,
                               int start_angel, int arc_angel,
                               boolean debug) {
            g.drawArc(x, y, width, height, start_angel, arc_angel);
            if (debug)
                g.drawRect(x, y, width, height);
        }
        public void paint(Graphics g) {
            //g.setColor(Color.YELLOW);
            g.setColor(new Color(181, 137, 0));
            g.fillOval(
                    k + CENTER_X - RADIUS_CIRCLE,
                    l + CENTER_Y - RADIUS_CIRCLE,
                    RADIUS_CIRCLE * 2,
                    RADIUS_CIRCLE * 2);
            //g.setColor(Color.BLACK);
            g.setColor(new Color(0, 43, 54));
            g.drawArc(
                    k + CENTER_X - RADIUS_MOUTH,
                    l + CENTER_Y - RADIUS_MOUTH,
                    RADIUS_MOUTH * 2,
                    RADIUS_MOUTH * 2,
                    180, 180);
            int [] xs = {CENTER_X - RADIUS_CIRCLE, CENTER_X},
                    dys = {RADIUS_CIRCLE / 2, RADIUS_CIRCLE / 2 - RADIUS_EYE * 2};
            for (int x : xs)
            /*
            for (int dy : dys)
                draw_arc_withrect(g, x, CENTER_Y - dy, RADIUS_CIRCLE, RADIUS_CIRCLE, 60, 60, true);
             */
                g.fillOval(
                        k + x + RADIUS_CIRCLE / 2 - RADIUS_EYE,
                        l + CENTER_Y - RADIUS_CIRCLE / 3,
                        RADIUS_EYE * 2,
                        RADIUS_EYE * 2);
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
    public MovingHuaji() {
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
