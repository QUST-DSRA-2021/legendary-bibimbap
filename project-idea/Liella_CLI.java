import java.util.Objects;
import java.util.Scanner;
import io.github.sandyzikun.charpainters.*;

public class Liella_CLI {
    public static void main(String[] args) {
        while (true) {
            // Prompts
            String[] multiline_prompts = {
                    "Input the index & the length of the item to print:",
                    "1. Basic Triangle",
                    "2. Reversed Triangle",
                    "3. Mirrored Triangle",
                    "4. Reversed Mirrored Triangle",
                    "Default: Diamond",
                    "(For example: >>> 0 4 <return>)",
                    "To exit, Just type \"exit\" and return."
            };
            for (int k = 0; k != multiline_prompts.length; ++k)
                System.out.println(multiline_prompts[k]);
            System.out.print(">>> ");

            // Inputting & Parsing
            String inputstr = new Scanner(System.in).nextLine();
            if (Objects.equals(inputstr, "exit"))
                return;
            String [] inputstrs = inputstr.split("\\s+");
            int PRINT_TYPE = Integer.parseInt(inputstrs[0]), NUM_LINES = Integer.parseInt(inputstrs[1]);

            // Outputting
            switch (PRINT_TYPE) {
                // Enhanced SWITCH Powered!! XD——
                case 1 -> new Basic_Tripainter(NUM_LINES).charpaint();
                case 2 -> new Reversed_Tripainter(NUM_LINES).charpaint();
                case 3 -> new Mirrored_Tripainter(NUM_LINES).charpaint();
                case 4 -> new Revmired_Tripainter(NUM_LINES).charpaint();
                default -> new Diamond_Painter(NUM_LINES).charpaint();
            }
        }
    }
}
