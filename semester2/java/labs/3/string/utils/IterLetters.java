package string.utils;

public class IterLetters {
    String str;
    int current;

    public IterLetters(String str) {
        if (str == null) throw new IllegalArgumentException("String must not be null.");
        this.str = str;
        current = 0;
    }

    public char next() {
        if (str.length() <= current) return ' ';
        return str.charAt(current++);
    }

    public void printNext() {
        IO.println(next());
    }

    public boolean hasNext() {
        return current < str.length();
    }

    public void reset() {
        current = 0;
    }


}