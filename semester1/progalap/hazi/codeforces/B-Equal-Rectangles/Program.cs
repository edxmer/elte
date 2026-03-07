

using System;

namespace B_Equal_Rectangles;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int q;
        int n;
        int[] sticks = new int[400];
        int[] halfsticks = new int[200];

        bool[] sol = new bool[500];

        int i, j;
        string[] line;
        int area;

        // Beolvasás

        int.TryParse(Console.ReadLine(), out q);
        for (i = 0; i < q; ++i) {
            
            // Beolvasás
            int.TryParse(Console.ReadLine(), out n);

            line = Console.ReadLine().Split();
            for (j = 0; j < 4*n; ++j)
                int.TryParse(line[j], out sticks[j]);

            // Feldolgozás
            sol[i] = true;

            Array.Sort(sticks, 0, 4*n);

            // Megnézem, hogy minden oldalnak van-e párja, majd ezeket kigyűjtöm
            
            for (j = 0; j < 2*n && sol[i]; ++j) {
                if (sticks[2*j] != sticks[2*j+1])
                    sol[i] = false;
                halfsticks[j] = sticks[2*j];
            }

            // Megnézem hogy a területek jók-e

            area = halfsticks[0] * halfsticks[2*n-1];
            for (j = 1; j < n && sol[i]; ++j) {
                if (area != halfsticks[j] * halfsticks[2*n-j-1])
                    sol[i] = false;
            }
        }

        // Kiírás

        for (i = 0; i < q; ++i) {
            if (sol[i])
                Console.WriteLine("YES");
            else
                Console.WriteLine("NO");
        }

    }
}