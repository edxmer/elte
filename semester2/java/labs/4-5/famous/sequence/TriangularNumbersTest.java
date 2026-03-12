package famous.sequence;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

class TriangularNumbersTest {

    @ParameterizedTest(name = "{0}. triangular number is {1}")
    @CsvSource("""
    1,  1
    2,  3
    3,  6
    4,  10
    5,  15
    6,  21
    7,  28
    8,  36
    9,  45
    10, 55
    """)
    void testGetTriangularNumber(int n, int expected) {
        assertEquals(expected, TriangularNumbers.getTriangularNumber(n));
    }

    @DisplayName("inputting 0 throws an exception")
    @Test
    void testZeroException() {
        boolean exception_thrown = false;
        try {
            TriangularNumbers.getTriangularNumber(0);
        }
        catch(Exception _) {
            exception_thrown = true;
        }
        assertTrue(exception_thrown);
    }

}