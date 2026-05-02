package agentic.workflow.llm;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

public class StructuredOutputTest {
    @Test
    public void testContainsExistingType() {
        StructuredOutput s = new StructuredOutput(
            SchemaType.INT,
            SchemaType.BOOLEAN,
            SchemaType.LIST(SchemaType.INT)
        );

        assertTrue(s.contains(SchemaType.INT));
    }

    @Test
    public void testContainsMissingType() {
        StructuredOutput s = new StructuredOutput(
            SchemaType.INT,
            SchemaType.BOOLEAN,
            SchemaType.LIST(SchemaType.INT)
        );
        
        assertFalse(s.contains(SchemaType.LIST(SchemaType.STRING)));
    }

    @Test
    public void testSize() {
        StructuredOutput s = new StructuredOutput(
            SchemaType.INT,
            SchemaType.BOOLEAN,
            SchemaType.LIST(SchemaType.INT)
        );

        assertEquals(3, s.size());
    }
}
