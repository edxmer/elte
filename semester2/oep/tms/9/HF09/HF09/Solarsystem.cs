using System.Numerics;

namespace HF09;

public class Solarsystem
{
    
    private List<Planet> planets;
    
    public Solarsystem(List<Planet> planets)
    {
        this.planets = planets;
    }

    public (bool, Starship) MaxFireShip()
    {
        bool l = false;
        int maxFireValue=0;
        Starship maxFireShip = null!;
        
        for (int i=0; i<planets.Count; ++i)
        {
            (bool exists, int maxvalue, Starship ship) = planets[i].MaxFireP();

            if      (!exists)                   {}
            else if (!l)                        { l = true; maxFireShip = ship; maxFireValue = maxvalue; }
            else if ( maxFireValue < maxvalue)  { maxFireShip = ship; maxFireValue = maxvalue; }
        }

        return (l, maxFireShip);
    }

    public bool MaxFireShip(out Starship bestship)
    {
        (bool b, bestship) = MaxFireShip();
        return b;
    }

    public List<Planet> Defenseless()
    {
        return planets.Where(e => e.ShipCount() == 0).ToList();
    }
}