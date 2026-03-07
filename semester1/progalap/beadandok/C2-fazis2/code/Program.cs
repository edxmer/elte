// Nagy Edömér Tamás CWQSKI
// edomer@student.elte.hu

using System;

namespace code
{
    class Program
    {
        
        static void Main(string[] args)
        {
            // Deklaráció
                 
            const int MAX_N = 100;
            int n, k, db, i, j, prev;
            int[,] versenyzok = new int[MAX_N, 5];
            int[] mindreszvett = new int[MAX_N];
            string[] linesplit;
            bool valid, valid2;
            int[] v_column;
            
            // Beolvasás
            n = 0; k = 0; // Hogy a fordító ne sírjon
            do
            {
                linesplit = Console.ReadLine().Split();
                valid = linesplit.Length == 2;
                if (valid) 
                {
                    valid = int.TryParse(linesplit[0], out n);
                    valid = valid && int.TryParse(linesplit[1], out k);
                    valid = valid && (2 <= k && k <= n && n <= MAX_N);
                }
                if (!valid)
                    Console.Error.WriteLine("Nem sikerült beolvasni a megadott 'n k' értékeket. Próbáld újra.");
            } while (!valid);
            

            v_column = new int[n];

            do
            {
                for (i = 0; i < n; ++i)
                {
                    do
                    {
                        linesplit = Console.ReadLine().Split();
                        valid = linesplit.Length == 5;
                        if (valid)
                        {
                            for (j = 0; j < 5; ++j)
                            {
                                valid = valid && int.TryParse(linesplit[j], out versenyzok[i, j]);
                                valid = valid && (0 <= versenyzok[i, j] && versenyzok[i, j] <= MAX_N);
                            }
                        }
                        if (!valid)
                            Console.Error.WriteLine("Nem jó a sor bemenete! Próbáld újra");
                    } while (!valid);
                }

                // Annak ellenőrzése, hogy mindegyik oszopban minden 1..h szám pontosan egyszer szerepel
                
                valid2 = true;
                for (i = 0; i < 5; ++i)
                {
                    // 1. put column into 1 dimensional array
                    // 2. sort array
                    // 3. check if every non-zero is +1 of the previous
                    for (j = 0; j < n; ++j)
                    {
                        v_column[j] = versenyzok[j, i];
                    }
                    
                    Array.Sort(v_column);
                    
                    prev = 0; 
                    for (j = 0; j < n && valid2; ++j)
                    {
                        if (v_column[j] != 0)
                        {
                            if (v_column[j] == prev + 1)
                            {
                                ++prev;
                            }
                            else
                            {
                                valid2 = false;
                            }
                        }
                    }
                }
                if (!valid2)
                    Console.Error.WriteLine("Nem megfelelők a megadott versenyzők adatai! Minden versenyen pontosan 1 darab [1..h] számnak szabad lennie! Próbáld újra.");
            } while (!valid2);


            // Feldolgozás

            db = 0;
            for (i = 0; i < n; ++i)
            {
                if (Mindpont(versenyzok, k, i))
                {
                    mindreszvett[db] = i;
                    ++db;
                }
            }



            // Kiírás
            if (db != 0)
            {
                Console.Error.Write("Minden versenyen pontot szerző versenyzők:\n - száma: ");
                Console.WriteLine(db);
                Console.Error.Write(" - indexei: ");
                for (i = 0; i < db; ++i)
                {
                    Console.Write("{0} ", mindreszvett[i] + 1);
                }
                Console.WriteLine();
            }
            else
            {
                Console.Error.Write("Nincs ilyen versenyző! (");
                Console.Write("0");
                Console.Error.Write(")");
                Console.WriteLine();
                Console.WriteLine();
            }
        
        }

        static bool Mindpont(int[,] vk, int k, int ind)
        {

            int j = 0;
            while (j < 5 && (vk[ind, j] > 0 && vk[ind, j] <= k))
                ++j;
            return j==5;
        }
    }
}
