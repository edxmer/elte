

namespace _1
{
    class Program
    {

        static int[] Beolvas() {
            int[] mer;
            int n, i;
            bool jo;
            

            do {
                Console.Error.Write("n: ");
                jo = int.TryParse(Console.ReadLine(), out n);
                jo = jo && (1 <= n && n <= 100);
                if (!jo)
                    Console.Error.WriteLine("Nem jó a bemenet. Próbáld újra.");
            } while (!jo);

            mer = new int[n];

            for (i = 0; i < n; ++i) {
                do {
                    Console.Error.Write($"{i+1}. merülés: ");
                    jo = int.TryParse(Console.ReadLine(), out mer[i]);
                    jo = jo && (1 <= mer[i] && mer[i] <= 20);
                    if (!jo)
                        Console.Error.WriteLine("Nem jó a bemenet. Próbáld újra.");
                } while (!jo);
            }


            return mer;
        }


        static (int, int[]) Kivalogat(int[] mer) {
        
            int db = 0;
            int i;
            int[] kim = new int[mer.Length];

            for (i=0; i < mer.Length; ++i) {
                if ( !(Voltmar(mer[i], i, mer)) ) {
                    kim[db] = mer[i];
                    ++db;
                }
            }

            return (db, kim);

        }

        static bool Voltmar(int mi, int ind, int[] miben) {
            int j;

            j = 0;
            while (j <= ind-1 && mi != miben[j])
                ++j;

            return j <= ind-1;
        }


        static void Kiir(int db, int[] m) {
            int i;
            
            Console.Error.Write("A megoldás:");

            for (i = 0; i < db; ++i) {
                Console.Write(m[i] + " ");
            }
            Console.WriteLine();
        }



        static void Main(string[] args)
        {
            // Deklaráció
            int[] mer, melysegek;
            int melydb;
            
            // Beolvasás
            mer = Beolvas();

            // Feldolgozás
            (melydb, melysegek) = Kivalogat(mer);

            // Kiírás
            Kiir(melydb, melysegek);
        }
    }
}
