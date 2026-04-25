using System;
namespace HF08;

public class Folder : Registration
{
    protected List<Registration> items = new();

    public override int GetSize()
    {
        return items.Sum(x => x.GetSize());
    }

    public void Add(Registration r) { items.Add(r); }
    public void Remove(Registration r) { items.Remove(r); }


}