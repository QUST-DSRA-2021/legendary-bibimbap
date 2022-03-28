package io.github.sandyzikun.swframes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Calc_Grid_Frame extends JFrame implements ActionListener {
    JTextField field_display = new JTextField();
    JPanel panel_upsided = new JPanel(new GridLayout(1, 2));
    JPanel panel_console = new JPanel(new GridLayout(4, 4));
    JButton[] buttons = {
            new JButton("C"),
            new JButton("<-"),


            new JButton("7"),
            new JButton("8"),
            new JButton("9"),
            new JButton("/"),

            new JButton("4"),
            new JButton("5"),
            new JButton("6"),
            new JButton("x"),

            new JButton("1"),
            new JButton("2"),
            new JButton("3"),
            new JButton("-"),

            new JButton("0"),
            new JButton("."),
            new JButton("="),
            new JButton("+"),
    };
    public Calc_Grid_Frame() {
        for (int k = 0; k != 2;  ++k)
            panel_upsided.add(buttons[k]);
        for (int k = 2; k != 18; ++k)
            panel_console.add(buttons[k]);
        this.setLayout(new BorderLayout());
        this.add(field_display, BorderLayout.NORTH);
        this.add(panel_upsided, BorderLayout.CENTER);
        this.add(panel_console, BorderLayout.SOUTH);
        this.setTitle("Calc."); //風に吹かれ飛んでゆけ　僕らが出会えたあの夏の日まで");
        this.setSize(390, 180);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }
    public void actionPerformed(ActionEvent ev) {
    }
}
