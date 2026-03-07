namespace HF02;

public record Position (int x, int y)
{
    public bool Inside(int l, int n, int k, int m)
    {
        return l <= x && x <= n && k <= y && y <= m;
    }

    public bool Direction()
    {
        return Inside(-1, 1, -1, 1) && ((x == 0 && y != 0) || (x != 0 && y == 0));
    }

    public static Position operator +(Position a, Position b)
    {
        return new Position(a.x + b.x, a.y + b.y);
    }

}