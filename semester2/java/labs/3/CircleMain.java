import plane.*;

class CircleMain {
    public static void main(String... args) {
        PublicCircle pc = new PublicCircle(1, 2, 3);

        IO.println(pc);
        IO.println("Area: %.4f".formatted(pc.getArea()));
        pc.r = -2;
        IO.println("Area: %.4f".formatted(pc.getArea()));

        Circle c = new Circle(3, 3, 4);
        IO.println(c);
        IO.println("Area: %.4f".formatted(c.getArea()));
        // c.r = 3;
        //c.setR(-5);
        c.setR(1.5);
        IO.println("Area: %.4f".formatted(c.getArea()));

    }
}