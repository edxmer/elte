package point2d;

class PointMain {
    public static void main(String... args) {

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
    }
}