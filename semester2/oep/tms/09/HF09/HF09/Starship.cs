using System.Numerics;

namespace HF09;

public abstract class Starship
{
    public string name { get; protected set; }
    public int Shield { get; protected set; }
    public Planet? planet { get; protected set; }
    protected int armor;
    protected int guard;

    protected Starship(string n, int sh, int ar, int g)
    {
        name = n;
        Shield = sh;
        armor = ar;
        guard = g;
        planet = null;
    }

    public void Protect(Planet p) {
        if (p == null) throw new Exception();
        if (planet != null) planet.LeftBy(this);
        planet = p;
        planet.ProtectedBy(this);
    }

    public void Leave()
    {
        if (planet == null) throw new Exception();
        planet.LeftBy(this);
        planet = null;
    }

    public abstract int FireP();
}

public class Wallbreaker : Starship
{
    public Wallbreaker(string n, int sh, int ar, int g) : base(n, sh, ar, g) {}
    public override int FireP()
    {
        return armor/2;
    }
}

public class Landingship : Starship
{
    public Landingship(string n, int sh, int ar, int g) : base(n, sh, ar, g) {}
    public override int FireP()
    {
        return guard;
    }
}

public class Lasership : Starship
{
    public Lasership(string n, int sh, int ar, int g) : base(n, sh, ar, g) {}
    public override int FireP()
    {
        return Shield;
    }
}