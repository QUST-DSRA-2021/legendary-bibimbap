package io.github.sandyzikun.charpainters;

/**
 * |-> abstract Charpainter extended by
 * |   |-> class Basic_Tripainter
 * |   |-> class Reversed_Tripainter
 * |   |-> class Mirrored_Tripainter
 * |   |-> class Revmired_Tripainter
 * |
 * |=> public Liella
 *     \_ main
 **/

abstract class Charpainter {
    int m_lns;
    public Charpainter() {
        m_lns = 4;
    }
    public Charpainter(int num_lines) {
        m_lns = num_lines;
    }
}