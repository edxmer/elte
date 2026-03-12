package plane;

public class Circle {
    private double x, y, r;

    // Constructors
    public Circle() {
        x = 0;
        y = 0;
        r = 1;
    }

    public Circle(double x, double y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    // Getters
    public double getX() { return x; }
    public double getY() { return y; }
    public double getR() { return r; }

    // Setters
    public void setX(double x) { this.x = x; }
    public void setY(double y) { this.y = y; }
    public void setR(double r) {
        //if (r <= 0) throw new RuntimeException("Error: radius must be positive!");
        if (r <= 0) throw new IllegalArgumentException("Error: radius must be positive!");
        this.r = r;
    }


    // Methods
    public double getArea() {
        return r*r*Math.PI;
    }

    @Override
    public String toString() {
        return "Circle{(%.4f, %.4f), %.4f}".formatted(x, y, r);
    }
}