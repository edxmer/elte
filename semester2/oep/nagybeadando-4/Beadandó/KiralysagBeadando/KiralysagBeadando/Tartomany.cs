namespace KiralysagBeadando;

#pragma warning disable IDE1006
#pragma warning disable IDE0290

public abstract class Tartomany
{
    public string nev { get; protected set; }

    protected Tartomany(string n)
    {
        nev = n;
    }

    public abstract void Accept(Lovag l);
    public abstract void AcceptForUtoCselekves(Lovag l);
}

public class KiralyiTartomany : Tartomany
{
    public KiralyiTartomany(string n) : base(n) { }
    public override void Accept(Lovag l) { l.Cselekves(this); }
    public override void AcceptForUtoCselekves(Lovag l) { l.UtoCselekves(this); }
}

public class EllensegesTartomany : Tartomany
{
    private int ellenfelEletero = 100;

    public EllensegesTartomany(string n) : base(n) { }

    public void Sebez(int dmg) { ellenfelEletero -= dmg; if (ellenfelEletero < 0) ellenfelEletero = 0; }

    public bool Halott() { return ellenfelEletero <= 0; }

    public void Semlegesit(TartomanyEnumerator enor)
    {
        Console.WriteLine($"{nev}(EllensegesTartomany) semlegesítve.");
        enor.Change(new SemlegesTartomany(nev));
    }

    public override void Accept(Lovag l) { l.Cselekves(this); }
    public override void AcceptForUtoCselekves(Lovag l) { l.UtoCselekves(this); }
}

public class SemlegesTartomany : Tartomany
{
    public SemlegesTartomany(string n) : base(n) { }

    public void TartomanyElfoglalasa(TartomanyEnumerator enor)
    {
        Console.WriteLine($"{nev}(SemlegesTartomany) elfoglalva.");
        enor.Change(new KiralyiTartomany(nev)); 
    }
    
    public override void Accept(Lovag l) { l.Cselekves(this); }
    public override void AcceptForUtoCselekves(Lovag l) { l.UtoCselekves(this); }
}