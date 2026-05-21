package resources;

import java.lang.IllegalArgumentException;
import java.util.Objects;

public abstract class Resource {
    private String position;
    private Type type;
    private boolean isStable;

    public String getPosition() { return position; }
    public Type getType() { return type; }
    public boolean getIsStable() { return isStable; }
    
    public Resource(String position, Type type) {
        if (position == null || position.length() < 4) throw new IllegalArgumentException();
        isStable = true;
    }

    public abstract void extendPosition();
    public abstract void collect();

    @Override
    public String toString() {
        return "Position: %s, Type: %s, isStable: %s".formatted(position, type.toString(), isStable);
    }

    @Override
    public boolean equals(Object obj) {
        if (this==obj) return true;
        if (obj==null || getClass() != obj.getClass()) return false;

        Resource other = (Resource)obj;
    
        return (position.substring(0, 4).equals(other.position.substring(0, 4))) && type.equals(other.type) && isStable == other.isStable;
    }

    @Override
    public int hashCode() {
        return Objects.hash(position.substring(0, 4), type, isStable);
    }
}
