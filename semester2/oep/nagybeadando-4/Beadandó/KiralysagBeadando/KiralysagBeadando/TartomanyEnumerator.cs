namespace KiralysagBeadando;

#pragma warning disable IDE0290

public class TartomanyEnumerator
{
    private int idx = 0;
    private readonly List<Tartomany> tartomanyok;

    public TartomanyEnumerator(List<Tartomany> t)
    {
        tartomanyok = t;
    }

    public void Next()
    {
        idx = (idx + 1) % tartomanyok.Count;
    }

    public void Prev()
    {
        idx = (idx - 1 + tartomanyok.Count) % tartomanyok.Count;
    }

    public Tartomany Current()
    {
        return tartomanyok[idx];
    }

    public void Change(Tartomany t)
    {
        tartomanyok[idx] = t;
    }
}