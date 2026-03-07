using System;

/*
  Készítette: Nagy Edömér Tamás
  Neptun: CWQSKI
  E-mail: edomer@student.elte.hu
  Feladat: Időjárás előrejelzés/Sok településen meleg napok
*/

namespace sok_telepules_magasabb_szintu {

    class Program
    {
        static void Main(string[] args)
        {
            // Deklaráció: bemenet
            int[,] h;
            // Deklaráció: kimenet
            int t;
            int[] ts;
            

            // Beolvasás
            h = beolvas();

            // Feldolgozás
            ts = Mintak.Kivalogat(0, h.GetLength(1)-1, i => legalabbfelen30(h, i), i => i);
            t = ts.Length;
            
            
            //Kiírás
            kiir(t, ts);

        }

        static int[,] beolvas() {
            if (Console.IsInputRedirected) {
                return beolvas_biro();
            }
            else {
                return beolvas_kezi();
            }
        }

        static int[,] beolvas_biro() {
            string[] sor; 
            int n, m, i, j;
            int[,] h;

            sor = Console.ReadLine().Split(" ");
            n = int.Parse(sor[0]);
            m = int.Parse(sor[1]);
            h = new int[n, m];

            for (i = 0; i < n; ++i) {
                sor = Console.ReadLine().Split(" ");
                for (j = 0; j < m; ++j) {
                    h[i, j] = int.Parse(sor[j]);
                }
            }
            
            return h;
        }

        static int[,] beolvas_kezi() {
            int n, m, i, j;
            bool jo;
            int[,] h;

            do {
                Console.ResetColor();
                Console.Write("A települések száma: ");
                jo = int.TryParse(Console.ReadLine(), out n) && 
                    1 <= n && n <= 1000;
                if (!jo) {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("1 és 1000 közötti egész számot adj meg!");
                }
            } while (!jo);
            
            do {
                Console.ResetColor();
                Console.Write("A napok száma: ");
                jo = int.TryParse(Console.ReadLine(), out m) && 
                    1 <= m && m <= 1000;
                if (!jo) {
                    Console.ForegroundColor = ConsoleColor.Red;
                    Console.WriteLine("1 és 1000 közötti egész számot adj meg!");
                }
            } while (!jo);
            
            h = new int[n, m];

            for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) {
                 do {
                    Console.ResetColor();
                    Console.Write("A {0}. település {1}. napjára jósolt fok: ", i+1, j+1);
                    jo = int.TryParse(Console.ReadLine(), out h[i, j]) && 
                        -50 <= h[i, j] && h[i, j] <= 50;
                    if (!jo) {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.WriteLine("-50 és 50 közötti egész számot adj meg!");
                    }
                } while (!jo);
            }

            return h;
        }
        
        static bool legalabbfelen30(int[,] h, int nap) {
            int i, db;
            
            db = 0;

            for (i = 0; i < h.GetLength(0); ++i) {
                if (h[i, nap] >= 30) {
                    ++db;
                }
            }

            // (n / 2) <= db
            // <=>
            // n <= db * 2
            return h.GetLength(0) <= db * 2;
        }


        static void kiir(int t, int[] ts) {
            int i;

            if (Console.IsInputRedirected) {
                Console.Write(t);
                
                for (i = 0; i < t; ++i) {
                    Console.Write(" {0}", ts[i]+1);
                }
                Console.WriteLine();
            }
            else {
                Console.ForegroundColor = ConsoleColor.Green;
                if (t == 0) {
                    Console.WriteLine("Nem volt ilyen nap.");
                }
                else {
                    Console.WriteLine("{0} ilyen nap volt: ", t);

                    for (i = 0; i < t; ++i) {
                        Console.WriteLine(" - {0}. nap", ts[i]+1);
                    }
                }
                Console.ResetColor();
            }
        }

    }

}
