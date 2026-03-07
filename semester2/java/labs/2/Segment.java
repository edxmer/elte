

public class Segment {

    Point start, end;

    public Segment(Point start, Point end) {
        this.start = start;
        this.end = end;

        if (start.x == end.x && start.y == end.y) throw new ZeroLengthSegmentException();
    }

    public Segment(double x1, double y1, double x2, double y2) {
        start = new Point(x1, y1);
        end = new Point(x2, y2);

        if (start.x == end.x && start.y == end.y) throw new ZeroLengthSegmentException();
    }


    public Line getLine() {
        if (start.y == end.y) return new Line(0, 1, end.x);
        else if (start.x == end.x) return new Line(1, 0, end.y);
        else {
            double a = (start.y - end.y) / (end.x - start.x);
            return new Line(a, 1, a*start.x + start.y);
        }
    }

    @Override
    public String toString() {
        return "{start: " + start + "; end: " + end + "}";
    }
}