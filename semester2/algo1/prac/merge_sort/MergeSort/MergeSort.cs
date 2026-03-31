namespace MergeSort;

public class MergeSortAlgorithm
{
    public static void Sort(int[] arr)
    {
        int n = arr.Length;
        int[] B = new int[n];
        Array.Copy(arr, B, n);
        Ms(B, arr, 0, n);
    }

    private static void Ms(int[] A, int[] B, int i, int j)
    {
        // Sort A[i..j) into B[i..j)

        int n = j - i;
        // Return clause
        if (n <= 1) return;

        // Disection point:
        int d = i + n/2;

        // I need to make sure that A[i..d) and A[d..j) are sorted from B
        Ms(B, A, i, d);
        Ms(B, A, d, j);

        // Now I need to merge A[i..d) and A[d..j) into B[i..j)
        Merge(A, i, d, A, d, j, B, i);

    }

    private static void Merge (int[] A, int aStart, int aEnd,
                               int[] B, int bStart, int bEnd,
                               int[] C, int cStart) 
    {
        // Merge A and B into C
        int a=aStart, b=bStart, c=cStart;

        while (a < aEnd && b<bEnd)
        {
            if (A[a] <= B[b])
            {
                C[c] = A[a];
                ++c;   ++a;
            } else
            {
                C[c] = B[b];
                ++c;   ++b;
            }
        }

        while (a < aEnd)
        {
            C[c] = A[a];
            ++c;   ++a;
        }

        while (b < bEnd)
        {
            C[c] = B[b];
            ++c;   ++b;
        }
    }
}