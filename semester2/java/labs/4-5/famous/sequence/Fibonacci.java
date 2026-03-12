package famous.sequence;

public class Fibonacci {
    public static int fib(int n) {
        if (n < 0) throw new IllegalArgumentException("The requested Fibonacci number's index cannot be negative!");
        
        int prev = 1;
        int curr = 0;

        for (int i = 0; i<n; ++i) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }

        return curr;
    }
}