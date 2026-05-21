namespace KiralysagBeadando;

#pragma warning disable IDE0290

public class LovagEnumerator
{
    private int idx;
    private readonly List<Lovag> lovagok;

    public LovagEnumerator(List<Lovag> l)
    {
        idx = 0;
        lovagok = l;
    }

    public void Next()
    {
        int i = 0;
        idx = (idx + 1) % lovagok.Count;
        while (Current().Meghalt() && i < lovagok.Count) { idx = (idx + 1) % lovagok.Count; ++i; }
        if (i == lovagok.Count) throw new Exception("Nincs élő lovag hátra.");
    }

    public Lovag Current()
    {
        return lovagok[idx];
    }
}