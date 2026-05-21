package agentic.workflow.util;

import java.io.IOException;

import agentic.workflow.Agent;

public class WorkflowFileWriterMain {
    public static void main(String... args) {
        String[] s = {
            "agent-examples/generated/customer-support-agent.agent",
            "agent-examples/generated/customer-support-agent.agent",
            "agent-examples/generated/recipe-advisor.agent",
            "agent-examples/generated/study-coach.agent",
            "agent-examples/generated/travel-planner.agent" 
        };
        
        try {
            WorkflowFileWriter.writeCalculatorAgent(s[0]);
            WorkflowFileWriter.writeCustomerSupportAgent(s[1]);
            WorkflowFileWriter.writeRecipeAdvisorAgent(s[2]);
            WorkflowFileWriter.writeStudyCoachAgent(s[3]);
            WorkflowFileWriter.writeTravelPlannerAgent(s[4]);
        } catch (IOException e) { IO.println("IOException thrown: %s".formatted(e.getMessage())); }

        try {
            for (String path: s) {
                Agent a = Agent.loadAgent(path);
                a.run();
                IO.println();
            }
        } catch (Exception e) {}
    }
}