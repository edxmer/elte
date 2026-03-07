
using System;


namespace _48_forgalomszamitas {
    class Program
    {
        // minden függvényből elérhető deklarációk
        static int n;
        static int m;
        static Adat[] adatok;
        static string kituntetett;

        struct Adat {
            public int hely;
            public string kat;
            public int db;
        }

        static void Main(string[] args)
        {
            // Deklaráció
            int i, ert;
            string[] sor;

            int jarmu_db;

            bool van_kit;
            int max_kit_ind;
            int max_kit_ert;

            int egyedi_db;

            int egykat_db;
            
            int dominans_db;
            int[] dominans;

            // Beolvasás
            sor = Console.ReadLine().Split();
            n = int.Parse(sor[0]);
            m = int.Parse(sor[1]);
            kituntetett = sor[2];
            
            adatok = new Adat[n];
            dominans = new int[n];

            for (i=0; i<n; ++i) {
                sor = Console.ReadLine().Split();
                adatok[i].hely = int.Parse(sor[0]);
                adatok[i].kat = sor[1];
                adatok[i].db = int.Parse(sor[2]);
                
            }

            // Feldolgozás
            
            // #1
            jarmu_db = 0;
            for (i=0; i<n; ++i) {
                jarmu_db += adatok[i].db;
            }

            // #2
            // FELTMAX(i=1..m, kituntetett_darab(i), kituntetett_darab(i) > 0)
            van_kit = false;
            max_kit_ert = -1;
            max_kit_ind = -1;
            for (i=1; i<=m; ++i) {
                ert = kituntetett_darab(i);
                if (!van_kit && ert > 0) {
                    van_kit = true;
                    max_kit_ind = i;
                    max_kit_ert = ert;
                } 
                else if (van_kit && ert > 0) {
                    if (ert > max_kit_ert) {
                        max_kit_ind = i;
                        max_kit_ert = ert;
                    }
                }
            }

            // #3
            // DARAB(i=0..n-1, elso(i))
            egyedi_db = 0;
            for (i=0; i<n; ++i) {
                if (elso(i)) {
                    ++egyedi_db;
                }
            }

            // #4
            // DARAB(i=1..m, egykat(i))
            egykat_db = 0;
            for (i=1; i<=m; ++i) {
                if (egykat(i)) {
                    ++egykat_db;
                }
            }

            // #5
            // (dominans_db, dominans) = KIVALOGAT(i=1..m, dominal(i), i)
            dominans_db = 0;
            for(i=1; i<=m; ++i) {
                if (dominal(i)) {
                    dominans[dominans_db] = i;
                    ++dominans_db;
                }
            }



            // Kiírás
            Console.WriteLine("#");
            Console.WriteLine(jarmu_db);
            Console.WriteLine("#");
            Console.WriteLine(van_kit ? max_kit_ind : -1);
            Console.WriteLine("#");
            Console.WriteLine(egyedi_db);
            Console.WriteLine("#");
            Console.WriteLine(egykat_db);
            Console.WriteLine("#");
            Console.Write(dominans_db);
            for (i=0; i<dominans_db; ++i) {
                Console.Write(" {0}", dominans[i]);
            }
            Console.WriteLine();

        



            

        }

        static int kituntetett_darab(int hely) {
            // SZUM(i=0..n-1, adatok[i].db, adatok[i].hely == hely && adatok[i].kat == kituntetett)
            int db, i;
            db = 0;
            for (i=0; i<n; ++i) if (adatok[i].hely == hely && adatok[i].kat == kituntetett) {
                db += adatok[i].db;
            }

            return db;
        }

        static bool elso(int ind) {
            // nem VAN(i=0..ind-1, adatok[i].kat == adatok[ind].kat)
            bool van;
            int i;
            van = false;
            for (i=0; i<ind; ++i) {
                if (adatok[i].kat == adatok[ind].kat) {
                    van = true;
                }
            }
            return !van;
        }

        static bool egykat(int hely) {
            // DARAB(i=0..n-1, hely == adatok[i].hely) == 1;
            int db, i;
            db = 0;
            for (i=0; i<n; ++i) {
                if (hely == adatok[i].hely)
                    ++db;
            }

            return db == 1;
        }

        static bool dominal(int hely) {
            // DB>0 && MAX == DB
            int kit_db;
            
            kit_db = kituntetett_db(hely);

            if (kit_db > 0 && (kit_db == max_db(hely)))
                return true;
            return false;

        }

        static int max_db(int hely) {
            // tudjuk, hogy csak akkor van meghívva, ha már fix van 1 kituntetett bejegyzés
            // FELTMAX            
            int i, maxdb;
            bool van;

            van = false;
            maxdb = -1;
            for (i=0; i<n; ++i) {
                if (!van && adatok[i].hely == hely) {
                    van = true;
                    maxdb = adatok[i].db;
                }
                else if (van && adatok[i].hely == hely) {
                    if (adatok[i].db > maxdb) {
                        maxdb = adatok[i].db;
                    }
                }
            }
            
            return maxdb;
        }
        
        static int kituntetett_db(int hely) { 
            // (van, ind) = KERES()
            // ha nincs, akkor 0
            int ind, i;
            bool van;
            
            van = false;
            ind = -1;
            for (i=0; i<n && !van; ++i) {
                if (adatok[i].hely == hely && adatok[i].kat == kituntetett) {
                    van = true;
                    ind = i;
                }
            }

            return van ? adatok[ind].db : 0;
        }

    }

}
