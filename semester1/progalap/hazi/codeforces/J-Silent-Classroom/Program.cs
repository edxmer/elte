
using System;

namespace J_Silent_Classroom;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int n;
        char[] names = new char[100]; 

        int[] letters = new int[26]; // c# -ban 0 inicializált alapból

        int i;
        int sol;
        int a, b;

        // Beolvasás
        int.TryParse(Console.ReadLine(), out n);

        for (i = 0; i < n; ++i) {
            names[i] = Console.ReadLine().ToCharArray()[0];

            ++letters[ names[i] - 'a' ];
        }

        // Feldolgozás

        sol = 0;

        for (i = 0; i < 26; ++i) {
            a = letters[i] / 2;
            b = letters[i] - a;

            if (a > 1)
                sol += a*(a-1)/2;
            if (b > 1)
                sol += b*(b-1)/2;   
        }

        // Kiírás
        Console.WriteLine(sol);

    }
}
