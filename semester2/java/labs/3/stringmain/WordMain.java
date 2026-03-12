package stringmain;

import string.utils.IterWords;

class WordMain {
    public static void main(String... args) {
        IterWords it = new IterWords("The quick brown fox has drowned in the toilet.");
        while (it.hasNext()) {
            it.printNext();
        }
        it.reset();

        for (int i=0; i<11; ++i) {
            it.printNext();
        }
    }
}