namespace HF04;

public struct Item
{
    public int pr;
    public String data;

    public Item()
    {
        data = "";
    }

    public override string ToString() => $"({pr}, \"{data}\")";
}