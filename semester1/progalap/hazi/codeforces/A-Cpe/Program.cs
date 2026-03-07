/*
    Nagy Edömér Tamás CWQSKI
    speci:
    stuki:
*/
using System;

namespace A_Cpe;

struct test_case {
    public int a,b,n;
}

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int t;
        test_case[] cases = new test_case[100];

        int[] sol = new int[100];

        int i;
        string[] line;

        // Beolvasás
        int.TryParse(Console.ReadLine(), out t);

        for (i = 0; i < t; ++i) {
            line = Console.ReadLine().Split();
            int.TryParse(line[0], out cases[i].a);
            int.TryParse(line[1], out cases[i].b);
            int.TryParse(line[2], out cases[i].n);
        }

        // Feldolgozás

        for (i = 0; i < t; ++i) {
            sol[i] = 0;
            while (!(cases[i].a > cases[i].n || cases[i].b > cases[i].n)) {
                if (cases[i].a > cases[i].b)
                    cases[i].b += cases[i].a;
                else
                    cases[i].a += cases[i].b;
                ++sol[i];
            }
        }

        // Kiírás

        for (i = 0; i < t; i++)
            Console.WriteLine(sol[i]);
    }
}
