using System;
using TextFile;

namespace hf6;

class Program
{
    public static void Main()
    {
        int bevet = 0;

        TextFileReader reader = new("input.txt");
        while (reader.ReadLine(out string line))
        {
            Szamla sz = new(line);
            bevet += sz.ossz;
        }

        Console.WriteLine(bevet);
    }
}