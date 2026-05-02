package agentic.workflow;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

import agentic.workflow.llm.SchemaType;
import agentic.workflow.llm.StructuredOutput;

public class WorkflowStepTest {
    @Test
    public void testExpectsStructuredOutput() {
        WorkflowStep w = new WorkflowStep(
            "name",
            "prompt",
            "systemPrompt",
            new StructuredOutput(SchemaType.INT, SchemaType.BOOLEAN)
        );
        assertTrue(w.expectsStructuredOutput());
    }
}