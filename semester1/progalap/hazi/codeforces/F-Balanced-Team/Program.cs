
using System;

namespace F_Balanced_Team;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int n;
        int[] skill;

        int sol;

        int start, end;


        // Beolvasás
        int.TryParse(Console.ReadLine(), out n);
        skill = Console.ReadLine()
                .Split(' ')
                .Select(int.Parse)
                .ToArray();
        

        // Feldolgozás

        Array.Sort(skill);

        start = 0;
        end = 0;
        sol = 1;

        while (end < n-1) {
            if (skill[start] + 5 >= skill[end+1]) {
                ++end;
                sol = Math.Max(sol, end-start+1);
            } else
                ++start;
        }

        // Kiírás

        Console.WriteLine(sol);
    }
}
