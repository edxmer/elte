// Nagy Edömér Tamás
// CWQSKI
// cwqski@inf.elte.hu
using System;


struct Lakas {
    public int terulet, ar;
}
class Program
{
    static void Main(string[] args)
    {
        // 1-es indexeléssel fogok dolgozni.

        // Deklaráció
        int n;
        Lakas[] l = new Lakas[101];
        int ind;
        int maxért;

        bool jo;
        int i;
        string[] line;


        // Beolvasás
        Console.Error.WriteLine(" -- Legdrágább lakás -- ");

        do {
            Console.Error.Write("n: ");
            jo = int.TryParse(Console.ReadLine(), out n);

            if (jo && !(1 <= n && n  <= 100))
                jo = false;
            
            if (!jo)
                Console.Error.WriteLine("Hibás bemenet! Egy 1 és 100 közötti egész számot adj meg!");
        } while (!jo);

        Console.Error.WriteLine("\nAdd meg a lakások adatait '(terület) (ár)' formátumban!");
        for (i = 1; i <= n; ++i) {
            do {
                Console.Error.Write($"{i}. lakás: ");
                line = Console.ReadLine().Split();
                
                if (line.Length == 2) {
                    jo = int.TryParse(line[0], out l[i].terulet);
                    jo = jo && int.TryParse(line[1], out l[i].ar);

                    if (jo && !(1 <= l[i].terulet && l[i].terulet <= 500 &&
                                1 <= l[i].ar && l[i].ar <= 1000 ))
                        jo = false;
                } else
                    jo = false;
                
                if (!jo)
                        Console.Error.WriteLine("Hibás bemenet!");
            } while (!jo);

            Console.Error.WriteLine($"» {i}. lakás sikeresen beolvasva {l[i].terulet} m² terület és {l[i].ar} millió forint ár adatokkal.\n");
        }

        // Feldolgozás
        maxért = l[1].ar;
        ind = 1;
        for (i = 2; i <= n; ++i) {
            if (l[i].ar > maxért) {
                maxért = l[i].ar;
                ind = i;
            }
        }

        // Kiírás
        Console.Error.Write("A legdrágább lakás sorszáma: ");
        Console.WriteLine(ind);
    }
}
