package array.util;

public class ArrayUtil {


    public ArrayUtil() {}

    public static int max(int[] A) {
        if (A.length == 0) return 0;
        
        int max = Integer.MIN_VALUE;
        for (int i=0; i<A.length; ++i) {
            if (max < A[i]) max = A[i];
        }

        return max;
    }

    public static int max2(int[] A) {
        if (A.length == 0) return 0;
        
        int max = Integer.MIN_VALUE;
        for (int i=0; i<A.length; ++i) {
            max = max<A[i] ? A[i] : max;
        }

        return max;
    }

    public static int max3(int[] A) {
        if (A.length == 0) return 0;
        
        int max = Integer.MIN_VALUE;
        for (int i=0; i<A.length; ++i) {
            max = Math.max(max, A[i]);
        }

        return max;
    }

    public static int max4(int[] A) {
        if (A.length == 0) return 0;
        
        int max = Integer.MIN_VALUE;
        for (int x : A) {
            max = Math.max(max, x);
        }

        return max;
    }

    public static int[] minMax(int[] A) {
        if (A.length == 0) return new int[] {0, 0};
        
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i=0; i<A.length; ++i) {
            max = max<A[i] ? A[i] : max;
            min = A[i]<min ? A[i] : min;
        }

        return new int[] {min, max};
    }
}