package math.operation.textual;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;


public class AdderTest {
    
    /*@Test
    void wrongInput() {
        boolean threw_exception = false;
        try {
            Adder.addAsText("5", 4); // This will not compile.
        } catch (Exception _) {
            threw_exception = true;
        }

        assertTrue(threw_exception);
    }*/

    @ParameterizedTest(name = "Adding {0}, {1}, expecting {2}")
    @CsvSource("""
    1, 0,       1
    0, 1,       1
    0, 0,       0
    0.0, 0,     0.000000
    0, 0.0,     0.000000
    """)
    void addZero(String a, String b, String expected) {
        assertEquals(Adder.addAsText(a, b), expected);
    }

    @ParameterizedTest(name = "Adding {0}, {1}, expecting {2}")
    @CsvSource("""
    51, 23,     74
    23, 51,     74
    -50, 50,    0
    50, -50,    0
    10, 1000,   1010
    1000, 10,   1010
    12.0, 13.0, 25.000000
    13.0, 12.0, 25.000000
    -40.0, 1.5, -38.500000
    1.5, -40.0, -38.500000
    """)
    void add(String a, String b, String expected) {
        assertEquals(Adder.addAsText(a, b), expected);
    }
}