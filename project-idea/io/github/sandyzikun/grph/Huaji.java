package io.github.sandyzikun.grph;

import javax.swing.*;
import java.awt.*;

public class Huaji extends JFrame {
    int FRAME_WIDTH = 960;
    int FRAME_HEIGHT = FRAME_WIDTH * 9 / 16;
    int RADIUS_CIRCLE = 216,
        RADIUS_MOUTH = 192,
        RADIUS_EYE = 15;
    int CENTER_X = FRAME_WIDTH / 2,
        CENTER_Y = FRAME_HEIGHT / 2;
    public Huaji() {
        this.setSize(FRAME_WIDTH, FRAME_HEIGHT);
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.setLocationRelativeTo(null);
    }
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
        g.setColor(Color.YELLOW);
        //g.setColor(new Color(181, 137, 0));
        g.fillOval(
            CENTER_X - RADIUS_CIRCLE,
            CENTER_Y - RADIUS_CIRCLE,
            RADIUS_CIRCLE * 2,
            RADIUS_CIRCLE * 2);
        //g.setColor(Color.BLACK);
        g.setColor(new Color(0, 43, 54));
        g.drawArc(
            CENTER_X - RADIUS_MOUTH,
            CENTER_Y - RADIUS_MOUTH,
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
            g.fillOval(x + RADIUS_CIRCLE / 2 - RADIUS_EYE, CENTER_Y - RADIUS_CIRCLE / 3, RADIUS_EYE * 2, RADIUS_EYE * 2);
    }
}
