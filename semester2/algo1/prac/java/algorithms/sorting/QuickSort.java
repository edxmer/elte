package algorithms.sorting;

public class QuickSort
{
    /* x <= y  <=> x.compareTo(y) <= 0 */
    public static <T extends Comparable<T>> void sort(T[] A)
    {
        qsort(A, 0, A.length-1);
    }

    private static <T extends Comparable<T>> void qsort(T[] A, int s, int e)
    {
        if (s < e)
        {
            int d = partition(A, s, e);
            qsort(A, s, d-1);
            qsort(A, d+1, e);
        }
    }

    private static <T extends Comparable<T>> int partition(T[] A, int s, int e)
    {
        // first choose the divider
        // 1 5 1 4 5 2
        int d = s + (e-s) / 2;
        swap(A, d, e);

        int firstLarger = s;
        while (firstLarger < e && A[firstLarger].compareTo(A[e]) <= 0) { ++firstLarger; }

        for (int i = firstLarger+1; i<e; ++i)
        {
            if (A[i].compareTo(A[e]) <= 0)
            {
                swap(A, firstLarger, i);
                ++firstLarger;
            }
        }

        swap(A, firstLarger, e);

        return firstLarger;
    }

    private static <T extends Comparable<T>> void swap(T[] L, int a, int b)
    {
        T temp = L[a];
        L[a] = L[b];
        L[b] = temp;
    }
}