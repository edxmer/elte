

using System;

namespace E_Long_Jumps;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int t;
        int n;
        int[] a = new int[200000];

        int i, j;

        int[] sol = new int[10000];


        // Beolvasás
        int.TryParse(Console.ReadLine(), out t);
        for (i = 0; i < t; ++i) {
            int.TryParse(Console.ReadLine(), out n);

            j = 0;
            foreach(string x in Console.ReadLine().Split(' ')) {
                int.TryParse(x, out a[j]);
                ++j;
            }

            // Feldolgozás

            sol[i] = a[n-1];

            for (j = n-1; j >= 0; --j) {
                if (j + a[j] < n)
                    a[j] += a[ j + a[j] ];
                
                // max keresés, hátulról

                if (a[j] > sol[i])
                    sol[i] = a[j];
            }
        }

        // Kiírás
        for (i = 0; i < t; ++i)
            Console.WriteLine(sol[i]);

    }
}
