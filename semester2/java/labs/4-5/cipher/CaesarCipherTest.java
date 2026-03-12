package cipher;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

public class CaesarCipherTest {
    @Test
    void noShiftEncrypt() {
        CaesarCipher cipher = new CaesarCipher(0);
        assertEquals("Hello there", cipher.encrypt("Hello there"));
    }

    @ParameterizedTest(name = "encryption {1} by {0} shift to get {2}")
    @CsvSource("""
    1, abc, bcd
    5, abc, fgh
    26, abc, abc
    260, abc, abc
    1, zzz, aaa
    10, ?._-, ?._-
    """)
    void encryptBy(int shift, String input, String output) {
        CaesarCipher cipher = new CaesarCipher(shift);
        assertEquals(output, cipher.encrypt(input));
    }

    @ParameterizedTest(name = "encryption then decryption of {1} by {0} shift is original")
    @CsvSource("""
    34, aksafgA
    1231231, asdfF-
    -124123, alsdle
    12134, lfladflalsl
    """)
    void inverseOperation(int shift, String input) {
        CaesarCipher cipher = new CaesarCipher(shift);
        assertEquals(input, cipher.decrypt(cipher.encrypt(input)));
    }

}