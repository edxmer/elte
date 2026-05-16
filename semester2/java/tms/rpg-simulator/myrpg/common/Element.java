package myrpg.common;

public enum Element {
    FIRE,
    WATER,
    EARTH,
    LIGHTNING,
    WIND;

    public String getName() {
        return toString().toLowerCase();
    }
}