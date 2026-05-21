import java.util.Arrays;

import algorithms.sorting.*;

public class Main
{
    public static void main()
    {
        Integer[] A = {6, 1, 7, 2, 5, 3, 4, 9, 6, 100};
        QuickSort.sort(A);
        IO.println(Arrays.toString(A));
    }
}