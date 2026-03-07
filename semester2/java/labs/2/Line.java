

public class Line {
    public double a, b, c; // ax + by = c

    public Line (double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    public boolean contains(Point p) {
        return a * p.x + b * p.y == c;
    }

    public boolean isParallelWith(Line l) {
        return a == l.a && b == l.b;
    }

    public boolean isOrthogonalTo(Line l) {
        return b*l.b + a*l.a == 0;
    }

    @Override
    public String toString() {
        return "(Line: a=%.2f b=%.2f c=%.2f)".formatted(a, b, c);
    }
}