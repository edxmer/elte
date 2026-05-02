package text.to.numbers;

import java.io.File;
import java.io.FileWriter;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.Scanner;

public class MultiLineFile
{   
    public static int addNumbers(String filename, char separator)
    throws IOException
    {
        int sum = 0;
        File file = new File(filename);
        
        String[] splitfilename = filename.split("/");
        splitfilename[splitfilename.length - 1] = "wrong." + splitfilename[splitfilename.length - 1];
        String wrong_filename = String.join("/", splitfilename);

        try 
        ( 
            Scanner scanner = new Scanner(file); 
            BufferedWriter writer = new BufferedWriter(new FileWriter(wrong_filename));
        )
        {
            while (scanner.hasNextLine())
            {
                String line = scanner.nextLine();
                String[] tokens = line.split(String.valueOf(separator));
                for (String token : tokens)
                {
                    try
                    {
                        int value = Integer.parseInt(token);
                        sum += value;
                    }
                    catch (Exception _)
                    {
                        String error_text = "Error: %s is not an int.".formatted(token);
                        System.err.println(error_text);
                        writer.write(error_text);
                        writer.newLine();
                    }
                }
            }
        } catch (IOException e) { throw e; }
        return sum;
    }
}