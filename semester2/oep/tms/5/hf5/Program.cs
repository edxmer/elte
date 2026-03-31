using System;
using TextFile;

namespace hf5;

class Program
{
    public static void Main()
    {
        int     max=0,      min=0;
        bool    lmax=false, lmin=false;
        
        TextFileReader x = new("input.txt");
        while (x.ReadInt(out int e))
        {
            if      (e >= 0)            {}
            else if (lmax && e < 0)     { if (e > max) max = e; }
            else if (!lmax && e < 0)    { lmax = true; max = e; }

            if      (e <= 0)            {}
            else if (lmin && e > 0)     { if (e < min) min = e; }
            else if (!lmin && e > 0)    { lmin = true; min = e; }
        }
        
        Console.WriteLine(lmax ? max : "nincs");
        Console.WriteLine(lmin ? min : "nincs");
    }    
}