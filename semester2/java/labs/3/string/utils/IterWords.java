package string.utils;

public class IterWords {
    String[] words;
    int index;

    public IterWords(String str) {
        if (str == null) throw new IllegalArgumentException("String cannot be null.");

        str = str.trim();
        if (str.isEmpty()) {
            words = new String[0];
        } else {
            words = str.split("\\s+");
        }

        index = 0;
    } 

    public String next() {
        if (words.length <= index) return "";
        return words[index++];
    }

    public void printNext() {
        IO.println(next());
    }

    public void reset() {
        index = 0;
    }

    public boolean hasNext() {
        return index < words.length;
    }
}