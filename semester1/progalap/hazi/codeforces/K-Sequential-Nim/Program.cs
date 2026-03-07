
using System;

namespace K_Sequential_Nim;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int t;

        int n;
        long[] a;

        bool[] firstWinners = new bool[1000];

        int i, j;

        // Beolvasás
        int.TryParse(Console.ReadLine(), out t);

        for (i = 0; i < t; ++i) {
            int.TryParse(Console.ReadLine(), out n);

            a = Console.ReadLine()
                .Split(' ')
                .Select(long.Parse)
                .ToArray();
            

            // Feldolgozás

            firstWinners[i] = true;

            for (j = 0; j < n-1 && a[j] == 1; ++j)
                if (a[j] == 1)
                    firstWinners[i] = ! firstWinners[i];

        }

        // Kiírás

        for (i = 0; i < t; ++i) {
            if (firstWinners[i])
                Console.WriteLine("First");
            else
                Console.WriteLine("Second");
        }

    }
}


/*


5
4
3
2

1.
1
4
3
2

2.
0
0
0
1


5 1 1 5 1 1 1

*/