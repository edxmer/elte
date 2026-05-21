using System.Diagnostics.Contracts;

namespace HF09;

public class Planet
{
    public string name { get; private set; }
    private List<Starship> ships;

    public Planet(string n) { name = n; ships = new(); }

    public void ProtectedBy(Starship h)
    {
        if (ships.Contains(h)) throw new Exception();
        ships.Add(h);
    }

    public void LeftBy(Starship h)
    {
        if (!ships.Contains(h)) throw new Exception();
        ships.Remove(h);
    }

    public int ShipCount()
    {
        return ships.Count;
    }

    public int TotalShield()
    {
        return ships.Sum(e => e.Shield);
    }

    public (bool, int, Starship) MaxFireP()
    {
        if (ShipCount() == 0) return (false, 0, null!);
        
        Starship maxFireShip = ships[0];
        int maxFireValue = ships[0].FireP();

        for (int i=1; i<ships.Count; ++i)
        if (maxFireValue < ships[i].FireP())
        {
            maxFireShip = ships[i];
            maxFireValue = ships[i].FireP();
        }

        return (true, maxFireValue, maxFireShip);

    }

    public bool MaxFireP(out double max, out Starship bestship)
    {
        (bool b, max, bestship) = MaxFireP();
        return b;
    }

}