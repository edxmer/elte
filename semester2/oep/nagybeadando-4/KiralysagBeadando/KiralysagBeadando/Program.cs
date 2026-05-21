using System.IO;

namespace KiralysagBeadando;


public class Program
{
    public static void Main()
    {
        Console.WriteLine("Hello there");
        (List<Lovag> lovagok, List<Tartomany> tartomanyok) = ReadData("in1.txt");
        Kiralysag k = new(lovagok, tartomanyok);


        while (!k.Befejezodott())
        {
            k.Cselekves();
        }


        Console.WriteLine("\n---\nA dicső harcnak vége.\n");
        if (k.EllensegesTartomanyokSzama() == 0)
        {
            Console.WriteLine("A hősi lovagjaink legyőzték garázda ellenfeleinket! Éljen a Királyság!");
        }
        else
        {
            Console.WriteLine("A hősi lovagjaink vereséget szenvedtek a garázda ellenfelektől. A Királyságunk egy sötét napja ez.");
        }

        Console.WriteLine("\nEmlékezünk meg a hősi halottakról:");
        foreach (Lovag l in k.lovagok)
        {
            if (l.Meghalt())
            {
                Console.WriteLine($"• Sir {l.nev}");
            }
        }
    }

    public static (List<Lovag>, List<Tartomany>) ReadData(string filepath)
    {
        List<Lovag> lovagok = [];
        List<Tartomany> tartomanyok = [];

        string[] lines = File.ReadAllLines(filepath);
        string[] tartomanyoksora = lines[0].Split(" ");

        for (int i = 0; i < tartomanyoksora.Length; i += 2)
        {
            string nev = tartomanyoksora[i];
            string tipus = tartomanyoksora[i + 1];
            switch (tipus)
            {
                case "K":
                    tartomanyok.Add(new KiralyiTartomany(nev));
                    break;
                case "E":
                    tartomanyok.Add(new EllensegesTartomany(nev));
                    break;
                case "S":
                    tartomanyok.Add(new SemlegesTartomany(nev));
                    break;
                default:
                    throw new Exception($"Hibás bemenet az első sorban: {tipus}");
            }
        }

        for (int i = 1; i < lines.Length; ++i)
        {
            string[] s = lines[i].Split(" ");
            string nev = s[0];
            string tipus = s[1];

            switch (tipus)
            {
                case "o":
                    lovagok.Add(new OvatosLovag(nev));
                    break;
                case "b":
                    lovagok.Add(new BatorLovag(nev));
                    break;
                case "v":
                    lovagok.Add(new VakmeroLovag(nev));
                    break;
                default:
                    throw new Exception($"Hibás bemenet a {i + 1}. sorban: {tipus}");
            }
        }

        return (lovagok, tartomanyok);
        
    }
}