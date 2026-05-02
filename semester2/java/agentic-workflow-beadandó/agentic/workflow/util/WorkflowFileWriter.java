package agentic.workflow.util;

import java.io.IOException;
import java.io.PrintWriter;

/**
 * Utility class for generating valid workflow agent files.
 * Each method writes a pre-defined agent workflow to the specified file path.
 */
public class WorkflowFileWriter {

    private WorkflowFileWriter() {
        // Utility class, not instantiable
    }

    private static void writeStep(
        PrintWriter pw,
        String name,
        String prompt,
        String systemPrompt,
        String output
    ) {
        pw.println("STEP");
        pw.println("name=" + name);
        pw.println("prompt=" + prompt);
        pw.println("systemPrompt=" + systemPrompt);
        pw.println("output=" + output);
        pw.println("ENDSTEP");
    }

    /**
     * Writes a Calculator agent workflow file.
     * Supports basic arithmetic operations: addition, subtraction, multiplication.
     */
    public static void writeCalculatorAgent(String filePath)
        throws IOException {
        try (PrintWriter pw = new PrintWriter(filePath)) {
            pw.println("AGENT: Calculator");
            writeStep(
                pw,
                "ParseInput",
                "Extract two numbers and an operator from the user's input.",
                "You are a calculator assistant. Parse arithmetic expressions.",
                "STRING"
            );
            writeStep(
                pw,
                "PerformCalculation",
                "Perform the arithmetic operation on the two parsed numbers.",
                "You are a calculator assistant. Compute the result.",
                "INT"
            );
            writeStep(
                pw,
                "FormatResult",
                "Format the result into a human-readable response.",
                "You are a calculator assistant. Present results clearly.",
                "STRING"
            );
        }
    }

    /**
     * Writes a TravelPlanner agent workflow file.
     * Helps users plan trips by searching destinations, booking flights and hotels.
     */
    public static void writeTravelPlannerAgent(String filePath)
        throws IOException {
        try (PrintWriter pw = new PrintWriter(filePath)) {
            pw.println("AGENT: TravelPlanner");
            writeStep(
                pw,
                "GatherPreferences",
                "Ask the user for their travel destination, dates, and budget.",
                "You are a travel planning assistant. Collect trip requirements.",
                "STRING"
            );
            writeStep(
                pw,
                "SearchFlights",
                "Find available flights matching the user's destination and dates.",
                "You are a travel planning assistant. Search for flight options.",
                "LIST(INT)"
            );
            writeStep(
                pw,
                "SearchHotels",
                "Find available hotels at the destination within the user's budget.",
                "You are a travel planning assistant. Search for hotel options.",
                "LIST(INT)"
            );
            writeStep(
                pw,
                "CheckWeather",
                "Retrieve the weather forecast for the destination during travel dates.",
                "You are a travel planning assistant. Provide weather information.",
                "STRING"
            );
            writeStep(
                pw,
                "SummarizePlan",
                "Generate a complete travel itinerary based on the gathered information.",
                "You are a travel planning assistant. Summarize the full trip plan.",
                "STRING"
            );
        }
    }

    /**
     * Writes a StudyCoach agent workflow file.
     * Helps students learn by creating study plans, quizzes, and summaries.
     */
    public static void writeStudyCoachAgent(String filePath)
        throws IOException {
        try (PrintWriter pw = new PrintWriter(filePath)) {
            pw.println("AGENT: StudyCoach");
            writeStep(
                pw,
                "AssessKnowledge",
                "Ask the student what subject they want to study and their current level.",
                "You are a study coach. Evaluate the student's starting point.",
                "STRING"
            );
            writeStep(
                pw,
                "CreateStudyPlan",
                "Create a structured study plan based on the subject and student level.",
                "You are a study coach. Design an effective learning schedule.",
                "STRING"
            );
            writeStep(
                pw,
                "GenerateQuiz",
                "Generate 5 multiple choice quiz questions on the studied topic.",
                "You are a study coach. Create relevant and challenging questions.",
                "LIST(INT)"
            );
            writeStep(
                pw,
                "EvaluateAnswers",
                "Evaluate the student's quiz answers and calculate the score.",
                "You are a study coach. Provide accurate and fair grading.",
                "INT"
            );
            writeStep(
                pw,
                "ProvideFeedback",
                "Give personalized feedback based on the student's quiz performance.",
                "You are a study coach. Offer constructive and encouraging feedback.",
                "STRING"
            );
        }
    }

    /**
     * Writes a RecipeAdvisor agent workflow file.
     * Suggests recipes based on available ingredients and dietary preferences.
     */
    public static void writeRecipeAdvisorAgent(String filePath)
        throws IOException {
        try (PrintWriter pw = new PrintWriter(filePath)) {
            pw.println("AGENT: RecipeAdvisor");
            writeStep(
                pw,
                "CollectIngredients",
                "Ask the user to list the ingredients they have available.",
                "You are a recipe advisor. Collect ingredient information from the user.",
                "STRING"
            );
            writeStep(
                pw,
                "CheckDietaryRestrictions",
                "Ask the user about any dietary restrictions or preferences.",
                "You are a recipe advisor. Identify dietary needs and restrictions.",
                "BOOLEAN"
            );
            writeStep(
                pw,
                "SuggestRecipes",
                "Suggest three suitable recipes based on the available ingredients and dietary restrictions.",
                "You are a recipe advisor. Recommend fitting and delicious recipes.",
                "STRING"
            );
            writeStep(
                pw,
                "GenerateShoppingList",
                "List any missing ingredients needed for the chosen recipe.",
                "You are a recipe advisor. Identify what ingredients still need to be bought.",
                "STRING"
            );
        }
    }

    /**
     * Writes a CustomerSupport agent workflow file.
     * Handles customer complaints by categorizing issues and proposing resolutions.
     */
    public static void writeCustomerSupportAgent(String filePath)
        throws IOException {
        try (PrintWriter pw = new PrintWriter(filePath)) {
            pw.println("AGENT: CustomerSupport");
            writeStep(
                pw,
                "GreetCustomer",
                "Welcome the customer and ask them to describe their issue.",
                "You are a customer support agent. Be polite and professional.",
                "STRING"
            );
            writeStep(
                pw,
                "CategorizeIssue",
                "Identify the category of the customer's issue: billing, technical, or shipping.",
                "You are a customer support agent. Accurately classify the issue type.",
                "STRING"
            );
            writeStep(
                pw,
                "CheckOrderStatus",
                "Look up the customer's order or account status based on their provided ID.",
                "You are a customer support agent. Retrieve accurate account information.",
                "BOOLEAN"
            );
            writeStep(
                pw,
                "ProposeResolution",
                "Suggest an appropriate resolution based on the issue category and order status.",
                "You are a customer support agent. Offer fair and practical solutions.",
                "STRING"
            );
            writeStep(
                pw,
                "CollectSatisfactionScore",
                "Ask the customer to rate their satisfaction with the support on a scale of 1 to 5.",
                "You are a customer support agent. Collect feedback professionally.",
                "INT"
            );
        }
    }
}
