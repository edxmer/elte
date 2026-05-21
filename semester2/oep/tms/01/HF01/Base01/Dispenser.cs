
public class Dispenser {
    private double max, dose, act;

    public Dispenser(double a, double b) {
        if (!(0<a && 0<b)) {
            throw new ArgumentException();
        }
        max = a;
        dose = b;
        act = 0.0;
    }

    public void Push() {
        act = Math.Max(act-dose, 0.0);
    }

    public void Fill() {
        act = max;
    }

    public bool Empty() {
        return act == 0;
    }

}
