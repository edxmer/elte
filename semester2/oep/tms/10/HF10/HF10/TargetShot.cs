namespace HF10;

public class TargetShot (string location)
{
    public List<Gift> Gifts { get; private set; } = []; // unique

    public void Shows(Gift a)
    {
        if (a.Target != null) throw new Exception();
        a.Target = this;
        Gifts.Add(a);
    }
}