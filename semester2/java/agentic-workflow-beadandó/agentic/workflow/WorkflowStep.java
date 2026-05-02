package agentic.workflow;

import java.util.ArrayList;

import agentic.workflow.llm.*;

public class WorkflowStep {
    private String name;
    public void setName(String name) { this.name = name; }
    public String getName() { return name; }

    private String prompt;
    public void setPrompt(String prompt) { this.prompt = prompt; }
    public String getPrompt() { return prompt; }

    private String systemPrompt;
    public void setSystemPrompt(String systemPrompt) { this.systemPrompt = systemPrompt; }
    public String getSystemPrompt() { return systemPrompt; }

    private StructuredOutput structuredOutput;
    public void setStructuredOutput(StructuredOutput structuredOutput) {
        this.structuredOutput = structuredOutput;
    }
    public StructuredOutput getStructuredOutput() {
        return structuredOutput;
    }

    // Opcionális tulajdonságok
    private double temperature = 0.6;
    public double getTemperature() { return temperature; }
    public void setTemperature(double temperature) throws IllegalArgumentException { 
        if (temperature < 0) throw new IllegalArgumentException();
        this.temperature = temperature; 
    }

    private String dependancy = null;
    public String getDependancy() { return dependancy; }
    public void setDependancy(String dependancy) { this.dependancy = dependancy; }

    private int retries = 0;
    public int getRetries() { return retries; }
    public void setRetries(int retries) throws IllegalArgumentException {
        if (retries < 0) throw new IllegalArgumentException();
        this.retries = retries; 
    }
    
    private ArrayList<String> tags = null;
    public ArrayList<String> getTags() { return new ArrayList<String>(tags); }
    public void setTags(ArrayList<String> tags) { this.tags = new ArrayList<String>(tags); }

    
    public WorkflowStep(
        String name, 
        String prompt, 
        String systemPrompt,
        StructuredOutput structuredOutput
    ) throws IllegalArgumentException {
        if (
            name == null || name.isBlank() ||
            prompt == null || prompt.isBlank() ||
            systemPrompt == null || systemPrompt.isBlank() ||
            structuredOutput == null
        ) throw new IllegalArgumentException();

        this.name = name;
        this.prompt = prompt;
        this.systemPrompt = systemPrompt;
        this.structuredOutput = structuredOutput;
    }

    public boolean expectsStructuredOutput() {
        return 0 < structuredOutput.size();
    }

    public String simulateResponse() {
        return simulateResponse(structuredOutput.getSchemaTypes()[0]);
    }

    private String simulateResponse(SchemaType schemaType) {
        return switch (schemaType) {
            case SchemaType.Primitive t -> switch (t) {
                case INT     -> "0";
                case STRING  -> "sample";
                case BOOLEAN -> "true";
            };
            case SchemaType.ListType t -> "[" + simulateResponse(t.valueType()) + "]";
            case SchemaType.MapType  t -> "{" + simulateResponse(t.valueType()) + ":" + simulateResponse(t.keyType()) + "}";
        };
    }
}
