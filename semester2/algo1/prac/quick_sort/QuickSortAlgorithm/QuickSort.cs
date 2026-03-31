namespace QuickSortAlgorithm;

class QuickSort
{
    public static void Sort(int[] A)
    {
        Qs(A, 0, A.Length-1);
    }

    private static void Qs(int[] A, int first, int last)
    {
        if (first < last)
        {
            int pivot = Partition(A, first, last);
            Qs(A, first, pivot-1);
            Qs(A, pivot+1, last);
        }
    }


        /// <summary>
        /// Partition on A[i..j] subarray
        /// </summary>
        /// <returns> the index of the pivot </returns>
    private static int Partition(int[] A, int first, int last)
    {

        // Select pivot
        int pivot = Random.Shared.Next(first, last+1);

        // Put pivot to the end
        Swap(A, pivot, last);

        // Find the first element larger than the pivot
        int larger = first;
        while (larger < last && A[larger] < A[last])
        {
            ++larger;
        }

        for (int i = larger + 1; i < last; ++i)
        {
            // If I find a smaller one, swap it with the first larger one,
            // then increase the index of the first larger one
            if (A[i] < A[last]) 
            {
                Swap(A, larger, i);
                ++larger;
            }
        }
        // 1 2 3 4 6 9. 7, 8 5

        // Now, A[larger, last) is greater than the pivot,
        // and A[first, larger) is smaller than the pivot.
        // Now, we need to swap(A, larger, last), in order 
        // to make everything on the left of it smaller,
        // and on the right of it larger.

        Swap(A, larger, last);

        // now, the pivot is on index larger

        return larger;
    }

    private static void Swap(int[] A, int i, int j)
    {
        int temp = A[i];
        A[i] = A[j];
        A[j] = temp;
    }
}