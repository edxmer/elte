

public class Main {
    public static void main (String... args) {
        String x = "Hello";
        String y = Text.prefixes(x);
        IO.println(y);


        IO.println(Text.searchInString("Asdasdasdasd", "ASDf"));


        LaundryList ls = new LaundryList(args);

        IO.println(ls.getItemCount());
        IO.println(ls.getKindCount());
        IO.println(ls.getCount("gatya"));
        IO.println(ls.getCount("hello"));
    }
}