
public class Text {
    public static String prefixes(String str) {
        String result = "";
        for (int i=0; i<str.length(); ++i) {
            result = result + str.substring(0, i+1);
        }
        return result;
    }

    public static boolean searchInString(String str, String to_search) {
        for (int i=0; i<str.length()-to_search.length()+1; ++i) {
            int j;
            for (j=0; j<to_search.length(); ++j) {
                if ( Character.toLowerCase(str.charAt(i+j)) != Character.toLowerCase(to_search.charAt(j)))
                {
                    break;
                } 
            }
            if (j==to_search.length()) return true;
        } 
        return false;
    }
}