namespace HF02;

public class Labyrinth
{
    private int n;
    private int m;
    private Dictionary<Position, Content> map = new();

    public Labyrinth(int n, int m)
    {
        this.n = n;
        this.m = m;
        
        for(int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
        {
            map[new Position(i, j)] = Content.EMPTY;
        }
    }

    public void Place(Position pos, Content c)
    {
        if (!map.ContainsKey(pos)) throw new Exception("Position is not found.");

        map[pos] = c;
    }

    public Content Spy(Position pos, Position dir)
    {
        if (!(pos.Inside(1, n, 1, m) && (pos + dir).Inside(1, n, 1, m) && dir.Direction()))
            throw new Exception("Spying failed.");

        return map[pos + dir];
    }

    public void Gather(Position pos)
    {
        if (!pos.Inside(1, n, 1, m)) throw new Exception("Gather failed: Position is outside map.");
        if (map[pos] != Content.TREASURE ) throw new Exception("Gather failed: Position is not treasure.");

        map[pos] = Content.EMPTY;
    }
}