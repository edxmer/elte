using System;

namespace HF03;
public class Diag 
{
    private double[] x;

    public Diag (int n) {
        if (n < 0) throw new Exception("n must be a non-negative integer");
        x = new double[n];
    }

    public double this[int i, int j] {
        get 
        {
            if ( !(0 <= i && i <= x.Length-1 && 0 <= j && j <= x.Length-1) ) throw new Exception();
            
            if (i==j) return x[i];
            else return 0;
        }
        set
        {


        }
    }

    public double Get(int i, int j) {
        if ( !(0 <= i && i <= x.Length-1 && 0 <= j && j <= x.Length-1) ) throw new Exception();
        
        if (i==j) return x[i];
        else return 0;
    }

    public void Set(int i, int j, double e)
    {
        if ( !(0 <= i && i < x.Length && 0 <= j && j < x.Length) ) throw new Exception();
        if (i==j) x[i] = e;
        else if (e != 0) throw new Exception();
    }

    public static Diag operator+(Diag a, Diag b) {
        if (a.x.Length != b.x.Length) throw new Exception();
        
        Diag c = new(a.x.Length);
        for (int i=0; i<c.x.Length; ++i) {
            c.x[i] = a.x[i] + b.x[i];
        }
        return c;
    }

    public static Diag operator*(Diag a, Diag b) {
        if (a.x.Length != b.x.Length) throw new Exception();

        Diag c = new(a.x.Length);
        for (int i=0; i<c.x.Length; ++i) {
            c.x[i] = a.x[i] * b.x[i];
        }
        return c;
    }
}