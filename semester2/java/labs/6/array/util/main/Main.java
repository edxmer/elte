import static array.util.ArrayUtil.*;

public class Main {
    public static void main() {
        
        IO.print("Array length: ");
        String arrayLenTxt = IO.readln();
        int arrayLen = Integer.parseInt(arrayLenTxt);

        int[] array = new int[arrayLen];

        for (int i=0; i<arrayLen; ++i) {
            IO.print("[%d]: ".formatted(i));
            int x = Integer.parseInt(IO.readln());
            array[i] = x;
        }

        int[] minmax = minMax(array);
        int minelem = minmax[0];
        int maxelem = max(array);

        IO.println(java.util.Arrays.toString(array));
        IO.println("min: %d".formatted(minelem));
        IO.println("max: %d".formatted(maxelem));
        IO.println("minmax: %s".formatted( java.util.Arrays.toString(minmax) ));
    }
}   