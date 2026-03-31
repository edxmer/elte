using System;

namespace MergeSort;

class Program
{
    static void Main()
    {
        int[] arr = [7, 1, 4, 8, 2, 4, 51, 4, 123, 5, 1, -142, -1, 41];
        MergeSortAlgorithm.Sort(arr);

        Console.WriteLine(String.Join(", ", arr));
    }
}
