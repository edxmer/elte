package agentic.workflow.llm;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

public class SchemaTypeTest {
    @Test
    public void testInt() {
        SchemaType t = SchemaType.valueOf("INT");
        assertEquals(SchemaType.INT, t);
    }

    @Test
    public void testListInt1() {
        SchemaType t = SchemaType.valueOf("LIST(INT)");
        assertEquals(SchemaType.LIST(SchemaType.INT), t);
    }

    @Test
    public void testListInt2() {
        SchemaType t = SchemaType.valueOf("LIST_INT");
        assertEquals(SchemaType.LIST(SchemaType.INT), t);
    }

    @Test
    public void testMapIntString1() {
        SchemaType t = SchemaType.valueOf("MAP_INT_STRING");
        assertEquals(SchemaType.MAP(SchemaType.INT, SchemaType.STRING), t);
    }

    @Test
    public void testMapIntString2() {
        SchemaType t = SchemaType.valueOf("MAP(INT,STRING)");
        assertEquals(SchemaType.MAP(SchemaType.INT, SchemaType.STRING), t);
    }

    @Test
    public void testMapListIntString() {
        SchemaType t = SchemaType.valueOf("MAP(LIST(INT),STRING)");
        assertEquals(SchemaType.MAP(SchemaType.LIST(SchemaType.INT), SchemaType.STRING), t);
    }
}