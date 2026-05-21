namespace HF10;

public abstract class Gift(ISize size)
{
    public TargetShot? Target { get; set; }

    public int Value()
    {
        return Points() * size.Multi();
    }

    public abstract int Points();
}

public class Ball(ISize size) : Gift(size)
{
    public override int Points() => 1;
}

public class Figure(ISize size) : Gift(size)
{
    public override int Points() => 2;
}

public class Plush(ISize size) : Gift(size) {
    public override int Points() => 3;
}