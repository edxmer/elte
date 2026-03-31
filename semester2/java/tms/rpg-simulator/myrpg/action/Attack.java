package myrpg.action;

public class Attack {
    private String element;
    private int damage;

    public Attack(String element, int damage) {
        if (damage < 0) throw new IllegalArgumentException("Negative damage");

        this.element = element;
        this.damage = damage;
    }

    public String getElement() { return element; }
    public int getDamage() { return damage; }
}