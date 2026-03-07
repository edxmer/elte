

public class LaundryList
{
    String[] args;

    public LaundryList (String[] args) {
        this.args = args;

        if ( !hasAllGoodNames() ) throw new IllegalArgumentException();
    }

    public boolean hasAllGoodNames() {
        if (args.length % 2 != 0) return false;
        

        try {
            for (int i=0; i<args.length; i+=2) {
                Integer.parseInt(args[i]);
            }
        }
        catch (Exception _) {
            return false;
        }

        for (int i=1; i<args.length; i+=2) {
            if (args[i].equals("")) return false;
        }

        return true;
    }

    public int getItemCount() {
        return args.length / 2;
    }

    public int getKindCount() {
        return args.length / 2;
    }

    public int getCount(String laundry) {
        for (int i=1; i<args.length; i+=2) {
            if (laundry.equals(args[i])) {
                return Integer.parseInt(args[i-1]);
            }
        }

        return -1;
    }
}