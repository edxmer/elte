package math.operation.textual;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;


public class AdderInvalidTest {
    @Test
    void wrongInput() {
        assertEquals(Adder.addAsText("", "5"), "Operands are not numbers.");
    }
}