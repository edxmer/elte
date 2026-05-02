package textfile;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;



public class Statistics
{
    public static int numberOfLines(String filename)
    throws IOException
    {
        int count = 0;
        try
        (
            Scanner scanner = new Scanner( new File(filename) );
        )
        {
            count = 1;
            while (scanner.hasNextLine()) { ++count; scanner.nextLine(); }
        } 
        catch (IOException e) { throw e; }
        return count;
    }

    public static int numberOfCharacters(String filename)
    throws IOException
    {

    }
}