package io.github.sandyzikun.mousevent;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Event_Adopter {
    JFrame wind = new JFrame("Sample of Event Adopter and Inner Classes");
    JTextField text = new JTextField(30);
    public Event_Adopter() {}
    class Simple_Listner extends MouseMotionAdapter {
        public void mouseDragged(MouseEvent e) {
            text.setText(new String("Mouse Dragging: X = " + e.getX() + "; Y = " + e.getY() + ";\n"));
        }
    }
    public void in_frame() {
        wind.add(new JLabel("Click & Drag the Mouse"), BorderLayout.NORTH);
        wind.add(text, BorderLayout.SOUTH);
        wind.addMouseMotionListener(new Simple_Listner());
        wind.setSize(300, 200);
        wind.setVisible(true);
    }
}
