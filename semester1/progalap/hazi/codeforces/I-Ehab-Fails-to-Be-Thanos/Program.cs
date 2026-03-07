
using System;

namespace I_Ehab_Fails_to_Be_Thanos;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int n;
        int[] a; // a hossza 2n

        int sum1, sum2;
        int i;
        bool isEqual;

        // Beolvasás
        int.TryParse(Console.ReadLine(), out n);
        a = Console.ReadLine()
            .Split(' ')
            .Select(int.Parse)
            .ToArray();
        
        // Feldolgozás

        Array.Sort(a);

        sum1 = 0;
        for (i = 0; i < n; ++i)
            sum1 += a[i];
        
        sum2 = 0;
        for (i = n; i < 2*n; ++i)
            sum2 += a[i];
        
        isEqual = sum1 == sum2;

        // Kiírás

        if (isEqual)
            Console.WriteLine(-1);
        else {
            Console.Write(a[0]);
            for (i = 1; i < 2*n; ++i)
                Console.Write(" {0}", a[i]);
            Console.WriteLine();
        }


    }
}
