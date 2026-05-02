package agentic.workflow.util;

import java.io.IOException;

import agentic.workflow.Agent;

public class WorkflowFileWriterMain {
    public static void main(String... args) {
        String
        s1 = "agent-examples/generated/customer-support-agent.agent",
        s2 = "agent-examples/generated/customer-support-agent.agent",
        s3 = "agent-examples/generated/recipe-advisor.agent",
        s4 = "agent-examples/generated/study-coach.agent",
        s5 = "agent-examples/generated/travel-planner.agent";
        
        try {
            WorkflowFileWriter.writeCalculatorAgent(s1);
            WorkflowFileWriter.writeCustomerSupportAgent(s2);
            WorkflowFileWriter.writeRecipeAdvisorAgent(s3);
            WorkflowFileWriter.writeStudyCoachAgent(s4);
            WorkflowFileWriter.writeTravelPlannerAgent(s5);
        } catch (IOException e) { IO.println("IOException thrown: %s".formatted(e.getMessage())); }

        try {
            Agent a1 = Agent.loadAgent(s1);
            a1.run();

            Agent a2 = Agent.loadAgent(s2);
            a2.run();
            
            Agent a3 = Agent.loadAgent(s3);
            a3.run();

            Agent a4 = Agent.loadAgent(s4);
            a4.run();

            Agent a5 = Agent.loadAgent(s5);
            a5.run();
        } catch (Exception e) {}
    }
}