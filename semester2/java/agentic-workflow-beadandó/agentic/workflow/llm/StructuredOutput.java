package agentic.workflow.llm;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

public class StructuredOutput {
    private final SchemaType[] schemaTypes;

    public SchemaType[] getSchemaTypes() {
        return schemaTypes.clone();
    } 
    
    public StructuredOutput(SchemaType... schemaTypes)
    throws IllegalArgumentException, NullPointerException {
        if (schemaTypes == null || schemaTypes.length == 0) throw new IllegalArgumentException();
        for (SchemaType t : schemaTypes) {
            if (t == null) throw new NullPointerException();
        }
        
        this.schemaTypes = schemaTypes.clone();
    }

    public boolean contains(SchemaType schemaType) {
        for (SchemaType t: schemaTypes) {
            if (t.equals(schemaType)) return true;
        }
        return false;
    }

    public int size() {
        return schemaTypes.length;
    }

    @Override
    public String toString() {
        return "{%s}".formatted(String.join(
            "; ", 
            ((ArrayList<SchemaType>)Arrays.asList(schemaTypes))
                .stream()
                .map(x -> x.toString())
                .collect(Collectors.toList())
        ));
    }
}