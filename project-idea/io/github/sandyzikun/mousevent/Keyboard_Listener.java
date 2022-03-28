package io.github.sandyzikun.mousevent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Keyboard_Listener extends JFrame implements KeyListener {
    JButton[] buttons = new JButton[3];
    int x, y;
    public Keyboard_Listener() {
        this.setSize(300, 300);
        this.setLayout(new FlowLayout());
        for (int k = 0; k != 3; ++k) {
            buttons[k] = new JButton(" " + k);
            buttons[k].addKeyListener(this);
            this.add(buttons[k]);
        }
        this.setDefaultCloseOperation(EXIT_ON_CLOSE);
        this.validate();
    }
    public void keyPressed(KeyEvent e) {
        JButton button = (JButton) e.getSource();
        x = button.getBounds().x;
        y = button.getBounds().y;
        switch (e.getKeyCode()) {
            case KeyEvent.VK_UP -> y = (y <= 2) ? 300 : (y - 2);
            case KeyEvent.VK_DOWN -> y = (y >= 300 - 2) ? 0 : (y + 2);
            case KeyEvent.VK_LEFT -> x = (x <= 2) ? 300 : (x - 2);
            case KeyEvent.VK_RIGHT -> x = (x >= 300 - 2) ? 0 : (x + 2);
        }
        button.setLocation(x, y);
    }
    public void keyTyped(KeyEvent e) {}
    public void keyReleased(KeyEvent e) {}
}
