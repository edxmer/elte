package agentic.workflow;

import static org.junit.jupiter.api.Assertions.*;

import java.io.IOException;
import java.nio.charset.IllegalCharsetNameException;

import module org.junit.jupiter;

import agentic.workflow.llm.SchemaType;
import agentic.workflow.llm.StructuredOutput;

public class AgentTest {
    @Test
    public void testStepCount() {
        Agent a = new Agent("test");
        assertEquals(0, a.getStepCount());
        a.addStep(new WorkflowStep("name", "prompt", "systemPrompt", new StructuredOutput(SchemaType.BOOLEAN)));
        assertEquals(1, a.getStepCount());
    }

    @Test
    public void testAddDuplicateStepRejected() {
        Agent a = new Agent("test");
        a.addStep(new WorkflowStep("name", "prompt", "systemPrompt", new StructuredOutput(SchemaType.BOOLEAN)));
        try {
            a.addStep(new WorkflowStep("name", "prompt", "systemPrompt", new StructuredOutput(SchemaType.INT)));
            fail("Added duplicate without exception.");
        }
        catch (IllegalArgumentException e) { return; }
        fail("Different exception thrown.");
    }

    @Test
    public void findStepByName() {
        Agent a = new Agent("test");
        WorkflowStep s = new WorkflowStep("name1", "prompt", "systemPrompt", new StructuredOutput(SchemaType.BOOLEAN));
        a.addStep(s);
        a.addStep(new WorkflowStep("name2", "prompt", "systemPrompt", new StructuredOutput(SchemaType.INT)));

        assertEquals(s, a.findStepByName("name1"));
    }

    @Test
    public void findStepByNameMissing() {
        Agent a = new Agent("test");
        a.addStep(new WorkflowStep("name1", "prompt", "systemPrompt", new StructuredOutput(SchemaType.BOOLEAN)));
        a.addStep(new WorkflowStep("name2", "prompt", "systemPrompt", new StructuredOutput(SchemaType.INT)));

        assertEquals(null, a.findStepByName("name3"));
    }


    @Test
    public void testLoadAgentSuccess() {
        try {
            Agent a = Agent.loadAgent("agent-examples/junit/code-debugger.agent");
        } 
        catch (IllegalArgumentException e) { fail("IllegalAgrumentException thrown."); }
        catch (WorkflowFormatException e) { fail("WorkflowFormatException thrown: %s".formatted(e.getMessage())); }
        catch (IOException e) { fail("IOException thrown."); }
    }

    @Test
    public void testLoadAgentRejectsMissingHeader() {
        try {
            Agent a = Agent.loadAgent("agent-examples/junit/missing-header.agent");
            fail("No exception thrown.");
        } 
        catch (IllegalArgumentException e) { fail("IllegalAgrumentException thrown."); }
        catch (WorkflowFormatException e) { }
        catch (IOException e) { fail("IOException thrown."); }
    }

    @Test
    public void testLoadAgentRejectsDuplicateStepNames() {
        try {
            Agent a = Agent.loadAgent("agent-examples/junit/duplicate-names.agent");
            fail("No exception thrown.");
        } 
        catch (IllegalArgumentException e) { }
        catch (WorkflowFormatException e) { fail("WorkflowFormatException thrown: %s".formatted(e.getMessage())); }
        catch (IOException e) { fail("IOException thrown."); }
    }

    
}