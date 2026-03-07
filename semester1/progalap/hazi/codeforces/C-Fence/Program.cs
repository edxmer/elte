
using System;


namespace C_Fence;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int t;
        int[] sides = new int[3];
        int[] sol = new int[1000];

        string[] line;
        int i;

        // Beolvasás
        int.TryParse(Console.ReadLine(), out t);

        for (i = 0; i < t; ++i) {
            line = Console.ReadLine().Split();
            int.TryParse(line[0], out sides[0]);
            int.TryParse(line[1], out sides[1]);
            int.TryParse(line[2], out sides[2]);

            // Feldolgozás

            sol[i] = (int)Math.Round(Math.Sqrt(Math.Pow(Math.Abs(sides[0]-sides[2]), 2) + Math.Pow(sides[1], 2)));
            // so ugly
        }

        // Kiírás

        for (i = 0; i < t; ++i)
            Console.WriteLine(sol[i]);

    }
}



