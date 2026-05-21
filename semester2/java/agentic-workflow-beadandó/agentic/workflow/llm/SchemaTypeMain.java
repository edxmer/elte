package agentic.workflow.llm;

public class SchemaTypeMain {
    public static void main(String... args) {
        SchemaType t1 = SchemaType.MAP(SchemaType.INT, SchemaType.LIST(SchemaType.BOOLEAN));
        // ugyanaz, mint:
        SchemaType t2 = SchemaType.valueOf("MAP_MAP_INT_STRING_LIST_BOOLEAN");
        IO.println(t1.toString());
        IO.println(t2.toString());
    }
}