package io.github.sandyzikun.swframes;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Login_Grid_Frame extends JFrame implements  ActionListener {
    JPanel[] all_panels = {
            new JPanel(new GridLayout(1, 3)),
            new JPanel(new GridLayout(2, 1)),
            new JPanel(new GridLayout(1, 1)),
    };
    JLabel label_avatar = new JLabel(new ImageIcon("avatar.jpeg"));
    JTextField jtf_username = new JTextField();
    JTextField jtf_password = new JTextField();
    JButton button_login = new JButton("ε=ε=(ノ≧∇≦)ノ");
    public Login_Grid_Frame() {
        all_panels[0].add(new JLabel());
        all_panels[0].add(label_avatar);
        all_panels[0].add(new JLabel());
        all_panels[1].add(jtf_username);
        all_panels[1].add(jtf_password);
        all_panels[2].add(button_login);
        // Summary
        this.setLayout(null); //new BorderLayout());
        all_panels[0].setBounds(0, -30, 390, 60);
        all_panels[1].setBounds(0, 30, 390, 60);
        all_panels[2].setBounds(0, 90, 390, 60);
        /*
        this.add(all_panels[0], BorderLayout.NORTH);
        this.add(all_panels[1], BorderLayout.CENTER);
        this.add(all_panels[2], BorderLayout.SOUTH);
        */
        for (int k = 0; k != all_panels.length; ++k)
            this.add(all_panels[k]);
        this.setTitle("Login...");
        this.setSize(390, 180);
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setVisible(true);
    }
    //Override??
    public void actionPerformed(ActionEvent e) {
    }
}
