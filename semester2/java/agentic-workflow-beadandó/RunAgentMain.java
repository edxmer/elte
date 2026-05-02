import java.io.IOException;

import agentic.workflow.Agent;
import agentic.workflow.WorkflowFormatException;

public class RunAgentMain {
    public static void main(String... args) {
        if (0 < args.length) {
            try {
                Agent a = Agent.loadAgent(args[0]);
                a.run();
            } 
            catch (IOException e){
                IO.println("IOException thrown: %s".formatted(e.getMessage()));
            }
            catch (WorkflowFormatException e) {
                IO.println("WorkflowFormatException thrown: %s".formatted(e.getMessage()));
            }
            catch (IllegalArgumentException e) {
                IO.println("IllegalArgumentException thrown: %s".formatted(e.getMessage()));
            }
        }
        else {
            IO.println("Must provide a path to the `.agent` file.");
        }
    }
}