

public class Point {
    public double x, y;
    public final int index;

    private static int indexCounter = 0;

    public Point() {
        x = 0;
        y = 0;
        
        index = indexCounter;
        ++indexCounter;
    }

    public Point(double x, double y) {
        this.x = x;
        this.y = y;

        index = indexCounter;
        ++indexCounter;
    }

    public void shift(double dx, double dy) {
        x += dx;
        y += dy;
    }

    public void shift(Point p) {
        x += p.x;
        x += p.y;
    }

    public double distance(Point p) {
        return Math.sqrt(Math.pow(x - p.x, 2) +  Math.pow(y - p.y, 2));
    }

    public static double distance(Point p1, Point p2) {
        return Math.sqrt(Math.pow(p1.x - p2.x, 2) + Math.pow(p1.y - p2.y, 2));
    }

    public static Point add(Point p1, Point p2) {
        return new Point(p1.x+p2.x, p1.y+p2.y);
    }
    
    @Override
    public String toString() {
        return "(%.1f, %.1f)".formatted(x, y);
    }

}