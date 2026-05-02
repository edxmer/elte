package agentic.workflow.llm;

import java.util.List;
import java.util.Arrays;
import java.util.Iterator;
import java.text.ParseException;

/* Eredeti
public enum SchemaType {
    INT,
    STRING,
    BOOLEAN,
    LIST_INT,
    LIST_STRING,
    MAP_STRING_STRING,
}
*/

// Sealed, hogy a switch-casekben ne kelljen defaultokat tenni ha mindegyiket lekezeljük,
// és hogy minden típus biztosan le legyen kezelve
// Azért így van megcsinálva, hogy minél közelebb legyen az eredetihez úgy, hogy támogasson
// bonyolultabb típusokat is
public sealed interface SchemaType permits SchemaType.Primitive, SchemaType.ListType, SchemaType.MapType {

    // A java megengedi a static típusok létrehozását interfaceken belül
    public static enum Primitive implements SchemaType {
        INT,
        STRING,
        BOOLEAN
    }

    public static record ListType(SchemaType valueType) implements SchemaType {
        @Override
        public String toString() {
            return "[%s]".formatted(valueType.toString());
        }
    }
    public static record MapType(SchemaType keyType, SchemaType valueType) implements SchemaType {
        @Override
        public String toString() {
            return "{%s:%s}".formatted(keyType, valueType);
        }
    }

    // A java interfacekben megenged static final mezőket
    public static final SchemaType INT = Primitive.INT;
    public static final SchemaType STRING = Primitive.STRING;
    public static final SchemaType BOOLEAN = Primitive.BOOLEAN;

    // A java interfacekben static metódusokat is megenged
    public static SchemaType LIST(SchemaType valueType) { return new ListType(valueType); }
    public static SchemaType MAP(SchemaType keyType, SchemaType valueType) { return new MapType(keyType, valueType); }


    public static SchemaType valueOf(String str) {
        List<String> tokens = Arrays.asList(str.split("[\\(\\)\\s_,]+")); 
        // Az ilyen fajta splitelés miatt működni fog ha az eredeti módon írjuk a típusokat,
        // és ha az új módon is.
        Iterator<String> it = tokens.iterator();
        try {
            SchemaType t = parseTokens(it);
            if (it.hasNext()) return null;
            return t;
        } catch (SchemaTypeParserException e) { return null; }
    }

    private static SchemaType parseTokens(Iterator<String> it) throws SchemaTypeParserException {
        if (it.hasNext()) {
            switch (it.next()) {
                case "INT":
                    return SchemaType.INT;
                case "STRING":
                    return SchemaType.STRING;
                case "BOOLEAN":
                    return SchemaType.BOOLEAN;
                case "LIST":
                    return SchemaType.LIST(parseTokens(it));
                case "MAP":
                    return SchemaType.MAP(parseTokens(it), parseTokens(it));
                default:
                    throw new SchemaTypeParserException();
            }
        }
        else throw new SchemaTypeParserException();
    }
}

// Annyi különbség van az eredetitől, hogy itt mindig a .equals-t kell használni,
// de úgyis nagyrészt switch-casekkel fogom kezelni, amik ezeket jól kezelik,
// és képesek pattern machingre is.