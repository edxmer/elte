package text.to.numbers;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

import java.io.IOException;

public class MultiLineFileTest {
    
    @Test
    public void SpaceSeparatorTest() {
        try
        {
            int sum = MultiLineFile.addNumbers("test_inputs/multiline_space.txt", ' ');
            assertEquals(756, sum);
        } catch (Exception e) { fail("Exception thrown: %s".formatted(e.getMessage())); }
    }

    @Test
    public void CommaSeparatorTest() {
        try
        {
            int sum = MultiLineFile.addNumbers("test_inputs/multiline_comma.txt", ',');
            assertEquals(755, sum);
        } catch (Exception e) { fail("Exception thrown: %s".formatted(e.getMessage())); }
    }

    @Test
    public void EmptyFile() {
        try
        {
            int sum = MultiLineFile.addNumbers("test_inputs/empty_file.txt", ' ');
            assertEquals(0, sum);
        } 
        catch (Exception _) { fail("Exception should not have been thrown."); return; }
    }

    @Test
    public void NonExistentFile() {
        try
        {
            MultiLineFile.addNumbers("doesnt_exist.txt", ' ');
        }
        catch (IOException e) { return; }
        catch (Exception e) { fail("Wrong exception thrown."); return; }
        fail("Exception not thrown.");
    }
}