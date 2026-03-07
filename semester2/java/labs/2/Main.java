import java.util.Locale;

/*
https://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
 */

public class Main {
    public static void main(String... args) {
        Locale.setDefault(Locale.of("en"));

        Point p = new Point(1, 2);

        if (2 <= args.length){
            p.x = Double.parseDouble(args[0]);
            p.y = Double.parseDouble(args[1]);
        }

        IO.println(p);

        p.shift(1, 2);

        IO.println(p);
        IO.println("Index: " + p.index);

        Point p2 = new Point(7, 7);

        IO.println(p2);
        IO.println("Index: " + p2.index);

        IO.println("p and p1 dist: %.2f".formatted(p.distance(p2)));

        Line l1 = new Line(1, 2, 3);
        Line l2 = new Line(1, 2, 5);
        Line l3 = new Line(1, -0.5, 2);

        IO.println(l1.isParallelWith(l2));
        IO.println(l1.isParallelWith(l3));
        IO.println(l1.isOrthogonalTo(l3));

        Line l4 = new Line(1, 0, 5);
        Line l5 = new Line(0, 1, 2);

        IO.println(l4.isOrthogonalTo(l5));


        Segment sg = new Segment(0, 0, 1, 0.5);
        IO.println(sg);

        Line sgline = sg.getLine();
        IO.println(sgline);
        
    }
}