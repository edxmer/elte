package math.operation.textual;

public class Adder {
    public static String addAsText(String str1, String str2) {
        try {
            int i1 = Integer.parseInt(str1);
            int i2 = Integer.parseInt(str2);
            return "%d".formatted(i1+i2);
        } catch (Exception _) {}

        try {
            double d1 = Double.parseDouble(str1);
            double d2 = Double.parseDouble(str2);
            return "%f".formatted(d1+d2);
        } catch (Exception _) {}

        return "Operands are not numbers.";
    }
}