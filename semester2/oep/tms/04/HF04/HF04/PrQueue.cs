using System;
using System.Linq;

namespace HF04;

public class PrQueue
{
    private List<Item> seq = new();

    public void SetEmpty()
    {
        seq.Clear();
    }

    public bool IsEmpty() => seq.Count == 0;

    public void Add(Item e)
    {
        seq.Add(e);
    }

    public Item GetMax()
    {
        if (IsEmpty()) throw new Exception("Zero length list.");
        return seq[MaxIndex()];
    }

    public Item RemMax()
    {
        if (IsEmpty()) throw new Exception("Zero length list.");
        int ind = MaxIndex();
        Item e = seq[ind];
        seq.RemoveAt(ind);
        return e;
    }


    private int MaxIndex()
    {
        if (IsEmpty()) throw new Exception("Zero length list.");
        return seq.Index().MaxBy(x => x.Item.pr).Index;
    }
}