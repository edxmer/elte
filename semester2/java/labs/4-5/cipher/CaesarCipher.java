package cipher;

class CaesarCipher {
    private final int shift;

    public CaesarCipher(int shift) {
        this.shift = shift;
    }

    public String encrypt(String raw) {
        StringBuilder out = new StringBuilder();
        for (int i=0; i<raw.length(); ++i) {
            char c = raw.charAt(i);
            if ('a' <= c && c <= 'z') {
                c -= 'a';
                int x = (int)c;
                x += shift;
                x %= 26;
                x += 26;
                x %= 26;
                c = (char)x;
                c += 'a';
            }
            out.append(c);
        }
        return out.toString();
    }

    public String decrypt(String raw) {
        StringBuilder out = new StringBuilder();
        for (int i=0; i<raw.length(); ++i) {
            char c = raw.charAt(i);
            if ('a' <= c && c <= 'z') {
                c -= 'a';
                int x = (int)c;
                x -= shift;
                x %= 26;
                x += 26;
                x %= 26;
                c = (char)x;
                c += 'a';
            }
            out.append(c);
        }
        return out.toString();
    }
}