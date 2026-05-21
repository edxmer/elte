namespace HF10;

public interface ISize
{
    public int Multi();
}

public class S : ISize
{
    private static S? instance = null;
    private S() { }
    public static S Instance() { instance ??= new S(); return instance; }

    public int Multi() => 1;
}

public class M : ISize
{
    private static M? instance = null;
    private M() { }
    public static M Instance() { instance ??= new M(); return instance; }

    public int Multi() => 2;
}


public class L : ISize {
    private static L? instance = null;
    private L() {}
    public static L Instance() { instance ??= new L(); return instance; }

    public int Multi() => 3;
}

public class XL : ISize
{
    private static XL? instance = null;
    private XL() { }
    public static XL Instance() { instance ??= new XL(); return instance; }

    public int Multi() => 4;
}