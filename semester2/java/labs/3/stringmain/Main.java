package stringmain;

import string.utils.IterLetters;

public class Main {
    public static void main(String... args) {
        IterLetters it = new IterLetters("Alma potato tej");
        while (it.hasNext()) {
            it.printNext();
        }
        it.reset();

        for (int i=0; i<30; ++i) {
            it.printNext();
        }
    }
}