
using System;

namespace H_Playing_with_Paper;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        long a, b;
        
        long sol;
        
        string[] buff;
        long temp;
        long x;

        // Beolvasás
        buff = Console.ReadLine().Split(' ');

        long.TryParse(buff[0], out a);
        long.TryParse(buff[1], out b);

        // Feldolgozás
        
        sol = 0;

        while (a > 0) {
            
            if (a < b) {
                temp = a;
                a = b;
                b = temp;
            }

            x = a / b;

            sol += x;

            a -= x * b;
        }


        // Kiírás

        Console.WriteLine(sol);


    }
}
