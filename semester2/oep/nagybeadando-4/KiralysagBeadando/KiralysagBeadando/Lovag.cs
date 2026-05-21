using System.Reflection.PortableExecutable;

namespace KiralysagBeadando;

#pragma warning disable IDE1006
#pragma warning disable IDE0290
#pragma warning disable CS8618

public abstract class Lovag
{
    public string nev { get; private set; }
    public int eletero { get; private set; } = 100;
    protected TartomanyEnumerator tartomanyEnor;

    protected Lovag(string n)
    {
        nev = n;
    }

    public void SetTartomanyEnor(TartomanyEnumerator t)
    {
        tartomanyEnor = t;
    }

    public bool Meghalt()
    {
        return eletero <= 0;
    }

    public abstract void Cselekves(KiralyiTartomany t);
    public abstract void Cselekves(EllensegesTartomany t);
    public abstract void Cselekves(SemlegesTartomany t);
    public abstract void UtoCselekves(KiralyiTartomany t);
    public abstract void UtoCselekves(EllensegesTartomany t);
    public abstract void UtoCselekves(SemlegesTartomany t);

    public Tartomany Hely()
    {
        return tartomanyEnor.Current();
    }

    protected void Sebez(int dmg)
    {
        switch (Hely())
        {
            case EllensegesTartomany t:
                eletero -= dmg;
                if (eletero < 0) eletero = 0;
                t.Sebez(dmg);
                Console.WriteLine($"A {t.nev} ellenséges tartomány ellenfelével {dmg} sebzést cserélt!");
                break;
            default:
                throw new Exception("Harcolni csak ellenséges tartományban lehet.");
        }
    }

    protected abstract bool Serult();
    protected abstract void Harcol();
    protected abstract int GyogyulasiFaktor();
    protected abstract int TamadasiFaktor();

    protected void KiralyiTartomanybaVisszater()
    {
        Console.WriteLine("Királyi tartományba visszatér:");
        while (Hely() is not KiralyiTartomany) {
            Console.Write($"    {Hely().nev} ({Hely().GetType().Name})");
            tartomanyEnor.Prev();
            Console.WriteLine($" -> {Hely().nev} ({Hely().GetType().Name})");
        }
    }

    protected void Gyogyul()
    {
        if (Hely() is not KiralyiTartomany) throw new Exception("Csak királyi tartományban lehet gyógyulni.");
        Console.Write($"{nev} gyógyul: {eletero} -> ");
        Random rand = new();
        eletero += rand.Next(0, GyogyulasiFaktor());
        if (100 < eletero) eletero = 100;
        Console.WriteLine($"{eletero}");
    }

    protected void KovetkezoTartomany()
    {
        Console.Write($"Következő tartományba megy: {Hely().nev} ({Hely().GetType().Name})");
        tartomanyEnor.Next();
        Console.WriteLine($" -> {Hely().nev} ({Hely().GetType().Name})");
    }
}


public class OvatosLovag : Lovag
{
    public OvatosLovag(string n) : base(n) { }

    protected override bool Serult() { return eletero <= 90; }

    protected override int GyogyulasiFaktor() { return 20; }

    protected override int TamadasiFaktor() { return 20; }

    protected override void Harcol()
    {
        Random rand = new();
        int sebzes = rand.Next(0, TamadasiFaktor());
        Sebez(sebzes);
    }

    public override void Cselekves(KiralyiTartomany t)
    {
        if (Serult()) { Gyogyul(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void Cselekves(SemlegesTartomany t)
    {
        if (Serult()) { KiralyiTartomanybaVisszater(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void Cselekves(EllensegesTartomany t)
    {
        if (Serult()) { KiralyiTartomanybaVisszater(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void UtoCselekves(KiralyiTartomany t) { }
    public override void UtoCselekves(SemlegesTartomany t) { }

    public override void UtoCselekves(EllensegesTartomany t)
    {
        Harcol();
        if (t.Halott()) t.Semlegesit(tartomanyEnor);
    }
}

public class BatorLovag : Lovag
{
    public BatorLovag(string n) : base(n) { }

    protected override bool Serult() { return eletero <= 40; }

    protected override int GyogyulasiFaktor() { return 30; }

    protected override int TamadasiFaktor() { return 40; }

    protected override void Harcol()
    {
        Random rand = new();
        int sebzes = rand.Next(0, TamadasiFaktor());
        Sebez(sebzes);
        if (!Serult())
        {
            sebzes = rand.Next(0, TamadasiFaktor());
            Sebez(sebzes);
        }
    }

    public override void Cselekves(KiralyiTartomany t)
    {
        if (Serult()) { Gyogyul(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void Cselekves(SemlegesTartomany t)
    {
        if (Serult()) { KiralyiTartomanybaVisszater(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void Cselekves(EllensegesTartomany t)
    {
        if (Serult()) { KiralyiTartomanybaVisszater(); }
        else
        {
            Harcol();
            if (t.Halott()) t.Semlegesit(tartomanyEnor);
        }
    }

    public override void UtoCselekves(KiralyiTartomany t) { }

    public override void UtoCselekves(SemlegesTartomany t)
    {
        t.TartomanyElfoglalasa(tartomanyEnor);
    }

    public override void UtoCselekves(EllensegesTartomany t)
    {
        Harcol();
        if (t.Halott()) t.Semlegesit(tartomanyEnor);
    }
}


public class VakmeroLovag : Lovag
{
    public VakmeroLovag(string n) : base(n) { }

    protected override bool Serult() { return false; }

    protected override int GyogyulasiFaktor() { return 40; }

    protected override int TamadasiFaktor() { return 40; }

    protected override void Harcol()
    {
        switch(Hely())
        {
            case EllensegesTartomany t:
                Random rand = new();
                int sebzes;
                while (!(Meghalt() || t.Halott()))
                {
                    sebzes = rand.Next(0, TamadasiFaktor());
                    Sebez(sebzes);
                }
                break;
            default:
                throw new Exception("Harcolni csak ellenséges tartományban lehet.");
        }

    }

    public override void Cselekves(KiralyiTartomany t)
    {
        if (Serult()) { Gyogyul(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void Cselekves(SemlegesTartomany t)
    {
        if (Serult()) { KiralyiTartomanybaVisszater(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void Cselekves(EllensegesTartomany t)
    {
        if (Serult()) { KiralyiTartomanybaVisszater(); }
        else { KovetkezoTartomany(); Hely().AcceptForUtoCselekves(this); }
    }

    public override void UtoCselekves(KiralyiTartomany t) { }
    
    public override void UtoCselekves(SemlegesTartomany t)
    {
        t.TartomanyElfoglalasa(tartomanyEnor);
    }

    public override void UtoCselekves(EllensegesTartomany t)
    {
        Harcol();
        if (t.Halott()) t.Semlegesit(tartomanyEnor);
    }
}