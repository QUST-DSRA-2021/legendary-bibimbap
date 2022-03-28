import io.github.sandyzikun.mousevent.*;

public class Liella_Listener {
    public static void main(String[] args) {
        switch (1) {
            case 2 -> new Keyboard_Listener().setVisible(true);
            case 1 -> new Event_Adopter().in_frame();
            default -> new Basic_Listener().to_win();
        }
    }
}
