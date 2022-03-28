package io.github.sandyzikun.swframes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Frame_Icon_Button extends JFrame implements ActionListener {
    JButton jbtn = new JButton("Open New Frame");
    public Frame_Icon_Button() {
        setSize(640, 400);
        setVisible(true);
        setTitle("照らし出して！");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new FlowLayout());
        add(jbtn);
        validate();
        jbtn.addActionListener(this);
    }
    public void actionPerformed(ActionEvent ev) {
        JFrame newframe = new JFrame("グリーンライツ");
        newframe.setSize(390, 200);
        newframe.setLocation(80, 80);
        newframe.setVisible(true);
    }
}
