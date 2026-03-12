package famous.sequence;

// You may copy these imports verbatim into your own tester code.
import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

import static famous.sequence.Fibonacci.*;

public class FibonacciTest {

    @DisplayName("Fibonacci number 0")
    @Test
    void testValue0() { assertEquals(0, fib(0)); }
    
    @DisplayName("Fibonacci number 1")
    @Test
    void testValue1() { assertEquals(1, fib(1)); }
    
    @DisplayName("Fibonacci number 2")
    @Test
    void testValue2() { assertEquals(1, fib(2)); }
    
    @DisplayName("Fibonacci number 3")
    @Test
    void testValue3() { assertEquals(2, fib(3)); }
    
    @DisplayName("Fibonacci number 4")
    @Test
    void testValue4() { assertEquals(3, fib(4)); }

    // *** Parameterized testing
    @ParameterizedTest(name = "fib({0}) should be {1}")
    /*
    // Alternative CsvSource method:
    @CsvSource({
        "0, 0", // input=0, expected=0
        "1, 1",
        "2, 1",
        "3, 2",
        "4, 3",
        "5, 5"
    })*/
   @CsvSource("""
    0,  0
    1,  1
    2,  1
    3,  2
    4,  3
    5,  5
   """) 
    void testFibonacciSequence(int n, int expectedResult) {
        assertEquals(expectedResult, fib(n));
    }
    
}