package famous.sequence;

public class TriangularNumbers {
    public static int getTriangularNumber(int n) {
        if (n<1) throw new IllegalArgumentException("The index of the triangular number must be positive.");

        int out = (n+1)*n/2;

        return out;
    }
}