namespace HF10;

public class Guest
{
    public string Name { get; private set; }
    private readonly List<Gift> prizes = [];

    #pragma warning disable IDE0290
    public Guest(string n) { Name = n; }

    public void Wins(Gift a)
    {
        if (a.Target == null || !a.Target.Gifts.Contains(a)) throw new Exception();
        a.Target.Gifts.Remove(a);
        prizes.Add(a);
    }

    public int Result(TargetShot c)
    {
        return prizes.Where(e => e.Target == c).Sum(e => e.Value());
    }
}