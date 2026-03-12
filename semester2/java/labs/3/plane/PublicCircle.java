package plane;

public class PublicCircle {
    public double x, y, r;

    public PublicCircle() {
        x = 0;
        y = 0;
        r = 1;
    }

    public PublicCircle(double x, double y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public double getArea() {
        return r*r*Math.PI;
    }

    @Override
    public String toString() {
        return "Circle{(%.4f, %.4f), %.4f}".formatted(x, y, r);
    }
}