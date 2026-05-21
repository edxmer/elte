namespace KiralysagBeadando;

public class Kiralysag {
    private LovagEnumerator lovagEnor;
    public List<Lovag> lovagok { get; private set; }
    public List<Tartomany> tartomanyok { get; private set; }

    public Kiralysag(List<Lovag> l, List<Tartomany> t)
    {
        if (t.Count == 0) throw new Exception("Szükséges legalább 1 tartomány.");
        if (t[0] is not KiralyiTartomany) throw new Exception("Az első tartománynak királyi tartománynak kell lennie.");

        lovagok = l; lovagEnor = new LovagEnumerator(l);
        tartomanyok = t;
        foreach (Lovag lovag in lovagok)
        {
            lovag.SetTartomanyEnor(new TartomanyEnumerator(t));
        }
    }

    public void Cselekves()
    {
        Lovag l = lovagEnor.Current();

        Console.WriteLine($"\n-- CSELEKVÉS {l.GetType().Name} Sir {l.nev}-nak:");
        Console.WriteLine($"Kezdeti tartomány: {l.Hely().nev} ({l.Hely().GetType().Name})");
        Console.WriteLine($"Kezdeti élterő: {l.eletero}/100");
        l.Hely().Accept(l);
        Console.WriteLine($"Cselekvés utáni tartomány: {l.Hely().nev} ({l.Hely().GetType().Name})");
        Console.WriteLine($"Cselekvés utáni életerő: {l.eletero}/100");


        try
        {
            lovagEnor.Next();
        }
        catch (Exception)
        {
            Console.WriteLine("\nVeszteség! Szörnyűség! Minden lovagunk halott!");
        }
    }

    public bool Befejezodott()
    {
        return EloLovagokSzama() == 0 || EllensegesTartomanyokSzama() == 0;
    }

    public int EloLovagokSzama()
    {
        int db = 0;
        foreach (Lovag l in lovagok)
        {
            if (!l.Meghalt()) db += 1;
        }
        return db;
    }

    public int EllensegesTartomanyokSzama()
    {
        int db = 0;
        foreach (Tartomany t in tartomanyok)
        {
            if (t is EllensegesTartomany) db += 1;
        }
        return db;
    }
}