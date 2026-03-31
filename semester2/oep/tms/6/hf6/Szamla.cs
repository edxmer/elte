using System;

namespace hf6;

public class Szamla
{
    public string nev { get; private set; }

    public int ossz { get; private set; }
    public Szamla(string line)
    {
        ossz = 0;

        string[] linesplit = line.Split(" ");
        nev = linesplit[0];
        for (int i=1; i<linesplit.Length; i+=2)
        {
            aruFelvetele(linesplit[i], int.Parse(linesplit[i+1]));
        }
    }

    public void aruFelvetele(string cikkszam, int ar)
    {
        ossz += ar;
    }
}