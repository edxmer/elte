package math.operation.safe;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;



class IncrementTest {


    @ParameterizedTest(name = "incremented {0} to {1}")
    @CsvSource({
        "0, 1",
        "-2147483648, -2147483647",
        "2147483647, 2147483647",
        "123213, 123214",
        "-31233, -31232",
        "-1, 0"
    })
    void testIncrementValues(int n, int expected) {
        assertEquals(expected, Increment.increment(n));
    }

}