package text.to.numbers;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

import java.io.IOException;

public class SingleLineFileTest {
    
    @Test
    public void CorrectFileReadTest() {
        try {
            int sum = SingleLineFile.addNumbers("correct_file.txt");
            assertEquals(-117, sum);
        } catch (Exception e) { fail("Exception thrown: %s".formatted(e.getMessage())); }
    }

    @Test
    public void EmptyFile() {
        try {
            SingleLineFile.addNumbers("empty_file.txt");
        } 
        catch (IOException e) { fail("Wrong exception thrown: IOException."); return; }
        catch (IllegalArgumentException e) { return; }
        catch (Exception e) { fail("Wrong exception thrown."); return; }
        fail("Exception not thrown.");
    }

    @Test
    public void NonExistentFile() {
        try {
            SingleLineFile.addNumbers("doesnt_exist.txt");
        }
        catch (IOException e) { return; }
        catch (Exception e) { fail("Wrong exception thrown."); return; }
        fail("Exception not thrown.");
    }
}