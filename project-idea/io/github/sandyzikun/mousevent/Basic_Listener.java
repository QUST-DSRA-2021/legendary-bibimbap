package io.github.sandyzikun.mousevent;

import javax.swing.*;
import java.awt.event.*;

public class Basic_Listener implements MouseMotionListener, MouseListener, WindowListener {
    JFrame wind = new JFrame("Sample Realizing 3 Interfaces");
    JTextField text = new JTextField(30);
    public void to_win() {
        wind.setSize(300, 200);
        wind.setVisible(true);
        wind.add(new JLabel("Click & Drag the Mouse"), "North");
        wind.add(text, "South");
        wind.addMouseMotionListener(this);
        wind.addMouseListener(this);
        wind.addWindowListener(this);
    }
    public void mouseDragged(MouseEvent e) {
        text.setText(new String("Mouse Dragging: X = " + e.getX() + "; Y = " + e.getY() + ";\n"));
    }
    public void mouseEntered(MouseEvent e) {
        text.setText(new String("Mouse Entering...\n"));
    }
    public void mouseExited(MouseEvent e) {
        text.setText(new String("Mouse Exiting...\n"));
    }
    public void windowClosing(WindowEvent e) {
        System.exit(0);
    }
    public void mouseMoved(MouseEvent e) {}
    public void mouseClicked(MouseEvent e) {}
    public void mousePressed(MouseEvent e) {}
    public void mouseReleased(MouseEvent e) {}
    public void windowOpened(WindowEvent e) {}
    public void windowIconified(WindowEvent e) {}
    public void windowDeiconified(WindowEvent e) {}
    public void windowClosed(WindowEvent e) {}
    public void windowActivated(WindowEvent e) {}
    public void windowDeactivated(WindowEvent e) {}
}
