package agentic.workflow;

import java.io.IOException;
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.HashSet;
import java.util.List;
import java.util.stream.Collectors;

import agentic.workflow.llm.SchemaType;
import agentic.workflow.llm.StructuredOutput;

public class Agent {
    
    private String name;
    public void     setName(String name)    { this.name = name; }
    public String   getName()               { return name; }
    
    private final List<WorkflowStep> steps;
    public List<WorkflowStep> getSteps() { return new ArrayList<WorkflowStep>(steps); }
    
    private final HashSet<String> stepNames;

    
    public Agent(String name)
    throws IllegalArgumentException {
        if (name == null || name.isBlank()) throw new IllegalArgumentException();
        this.name = name;
        steps = new ArrayList<WorkflowStep>();
    }

    
    public void addStep(WorkflowStep step)
    throws IllegalArgumentException {
        if (step == null) throw new IllegalArgumentException();
        if (stepNames.contains(step.getName())) throw new IllegalArgumentException();

        stepNames.add(step.getName());
        steps.add(step);
    }

    public int getStepCount() { return steps.size(); }

    public WorkflowStep findStepByName(String stepName)
    throws IllegalArgumentException {
        if (stepName == null || stepName.isBlank()) throw new IllegalArgumentException();
        String strippedStepName = stepName.strip();

        for (WorkflowStep s: steps) {
            if (strippedStepName.equals(s.getName().strip())) return s;
        }
        return null;
    }

    public void run() {
        IO.println("« RUNNING WORKFLOW »".formatted(name));
        IO.println(toString());
        IO.println("+++");
        for (int i=0; i<steps.size();++i) {
            WorkflowStep step = steps.get(i);
            IO.println("%2d.: %s".formatted(i+1, step.getName()));
            IO.println("response: `%s`".formatted(step.simulateResponse()));
            IO.println("•••");
        }
    }

    public static Agent loadAgent(String filename)
    throws IllegalArgumentException, WorkflowFormatException, IOException {
        if (filename==null || filename.isBlank()) throw new IllegalArgumentException();
        
        try ( BufferedReader reader = new BufferedReader(new FileReader(filename)); ) {
            
            String[] tokens = reader.readLine().split(":");

            if (tokens == null || tokens.length != 2 || !tokens[0].strip().equals("AGENT"))
                throw new WorkflowFormatException("First line's format is not 'AGENT: ...'");
            
            Agent agent = new Agent(tokens[1].strip());
            
            String line; 
            while ( (line = reader.readLine()) != null) {
                if (!line.equals("STEP")) throw new WorkflowFormatException("Workflow step does not begin with 'STEP'");
                agent.addStep(parseStep(reader));
            }

            return agent;
        }
        catch (Exception e) { throw e; }
    }

    private static WorkflowStep parseStep(BufferedReader reader)
    throws IOException, WorkflowFormatException {
        // Kötelező tulajdonságok
        String line;
        String name=null, prompt=null, systemPrompt=null;
        SchemaType type=null;
        // Opcionális tulajdonságok
        String temperature=null, dependancy=null, retries=null, tags=null;
        
        while ( (line = reader.readLine()) != null ) {
            if (line.equals("ENDSTEP")) {
                if (name==null || prompt==null || systemPrompt==null || type==null) 
                    throw new WorkflowFormatException("Did not provide all necessary properties.");
                
                WorkflowStep step = new WorkflowStep(name, prompt, systemPrompt, new StructuredOutput(type));

                // Opcionális tulajdonságok beállítása
                try { if (temperature != null) step.setTemperature(Double.parseDouble(temperature)); } 
                catch (NumberFormatException e) { throw new WorkflowFormatException("Temperature is not a double."); }
                catch (IllegalArgumentException e) { throw new WorkflowFormatException("Temperature is negative."); }
                
                if (dependancy != null) step.setDependancy(dependancy);

                try { if (retries != null) step.setRetries(Integer.parseInt(retries)); } 
                catch (NumberFormatException e) { throw new WorkflowFormatException("Retries is not an integer."); }
                catch (IllegalArgumentException e) { throw new WorkflowFormatException("Retries is negative."); }

                if (tags != null) step.setTags( (ArrayList<String>)Arrays.asList(tags.split(",")) );

                return step;
            }

            String[] tokens = line.split("=");
            if (tokens == null || tokens.length != 2) 
                throw new WorkflowFormatException("Invalid format in a step: '%s'".formatted(line));
            tokens[1] = tokens[1].strip();
            
            switch (tokens[0].strip()) {
                case "name":
                    name = tokens[1];
                    break;
                case "prompt":
                    prompt = tokens[1];
                    break;
                case "systemPrompt":
                    systemPrompt = tokens[1];
                    break;
                case "output":
                    type = SchemaType.valueOf(tokens[1]);
                    break;
                
                case "temperature":
                    temperature = tokens[1];
                    break;
                case "dependancy":
                    dependancy = tokens[1];
                    break;
                case "retries":
                    retries = tokens[1];
                    break;
                case "tags":
                    tags = tokens[1];
                    break;
                
                default:
                    throw new WorkflowFormatException("Invalid format in a step: '%s'".formatted(line));
            }
        }
        throw new WorkflowFormatException("Invalid step format.");
    }

    @Override
    public String toString() {
        return "Agent:%s steps={%s}".formatted(name, String.join("; ", steps.stream().map(x -> x.getName()).collect(Collectors.toList())));
    }
}