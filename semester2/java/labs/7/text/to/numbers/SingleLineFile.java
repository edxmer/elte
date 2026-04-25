package text.to.numbers;

import java.io.File;
import java.util.Scanner;
import java.io.IOException;

public class SingleLineFile {

    public static int addNumbers(String filename) 
    throws IOException, IllegalArgumentException {
        File file = new File(filename);
        try (Scanner scanner = new Scanner(file)) {
            if (!scanner.hasNextLine()) throw new IllegalArgumentException();

            String line = scanner.nextLine();
            String[] tokens = line.split(" ");

            int sum = 0;
            for (String token : tokens) {
                try {
                    int value = Integer.parseInt(token);
                    sum += value;
                }
                catch (Exception _) { System.err.println("Error: %s is not an int.".formatted(token)); }
            }
            return sum;
        } catch (Exception e) { throw e; }
    }
}