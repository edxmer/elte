namespace HF10;

public class AmPark
{
    private readonly List<TargetShot> targets;
    private readonly List<Guest> guests = [];

    public AmPark(List<TargetShot> c)
    {
        if (c.Count < 2) throw new Exception();
        targets = c;
    }

    public void Receives(Guest v)
    {
        if (guests.Contains(v)) throw new Exception();
        guests.Add(v);
    }

    public string Best(TargetShot c)
    {
        if (guests.Count == 0) throw new Exception();

        int max = guests[0].Result(c), r;
        Guest elem = guests[0];

        for (int i = 1; i < guests.Count; ++i)
        {
            if (max < (r = guests[i].Result(c)))
            {
                max = r;
                elem = guests[i];
            }
        }

        if (max == 0) throw new Exception();
        return elem.Name;
        
    }
}