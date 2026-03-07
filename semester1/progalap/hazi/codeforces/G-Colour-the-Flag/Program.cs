
using System;

namespace G_Colour_the_Flag;

class Program
{
    static void Main(string[] args)
    {
        // Deklaráció
        int t;
        int n, m;
        char[,] colour = new char[50,50];

        int i, j, k;
        string[] buff1;
        char first;
        bool isPossible;

        // solutions
        char[] firsts = new char[100];
        bool[] possibilites = new bool[100];
        int[] ns = new int[100];
        int[] ms = new int[100];


        // Beolvasás

        int.TryParse(Console.ReadLine(), out t);
        for(i = 0; i < t; ++i) {
            buff1 = Console.ReadLine().Split(' ');
            int.TryParse(buff1[0], out n);
            int.TryParse(buff1[1], out m);

            
            for (j=0; j < n; ++j){
                k = 0;
                foreach(char x in Console.ReadLine().ToCharArray())
                    colour[j, k++] = x;
            }
                
            
            // Feldolgozás

            first = '?';
            isPossible = true;
            
            for (j = 0; j < n && isPossible; ++j)
                for (k = 0; k < m && isPossible; ++k) {
                    if (colour[j, k] != '.') {

                        if (first == '?') {
                            // Ha páratlan mező
                            if ((j + k) % 2 == 1) {
                                first = colour[j, k];
                            } else { // Ha páros a mező
                                if (colour[j, k] == 'W')
                                    first = 'R';
                                else
                                    first = 'W';
                            }

                        } else {

                            // Ha páratlan mező
                            if ((j + k) % 2 == 1) {
                                if (first != colour[j, k])
                                    isPossible = false;
                            } else { // Ha páros a mező
                                if (first == colour[j, k])
                                    isPossible = false;
                            }

                        }

                    }
                }

            possibilites[i] = isPossible;
            firsts[i] = first;
            ns[i] = n;
            ms[i] = m;
        }

        // Kiírás

        for (i = 0; i < t; ++i) {
            if (possibilites[i]) {
                Console.WriteLine("YES");

                if (firsts[i] == '?') {
                    for(j = 0; j < ns[i]; ++j) {
                        for (k = 0; k < ms[i]; ++k) {

                            // Ha páratlan mező
                            if ((j + k) % 2 == 1) {
                                Console.Write('W');
                            } else { // Ha páros a mező
                                Console.Write('R');
                            }

                        }
                        Console.WriteLine();
                    }
                }
                else {
                    for(j = 0; j < ns[i]; ++j) {
                        for (k = 0; k < ms[i]; ++k) {

                            // Ha páratlan mező
                            if ((j + k) % 2 == 1) {
                                Console.Write(firsts[i]);
                            } else { // Ha páros a mező
                                if (firsts[i] == 'W')
                                    Console.Write('R');
                                else
                                    Console.Write('W');
                            }

                        }
                        Console.WriteLine();
                    }
                }
            }
            else
                Console.WriteLine("NO");
        }
    


    }
}
