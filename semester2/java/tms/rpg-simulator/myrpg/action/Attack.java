package myrpg.action;

import myrpg.common.Element;

public class Attack {
    private Element element;
    private int damage;

    public Attack(Element element, int damage) {
        if (damage < 0) throw new IllegalArgumentException("Negative damage");

        this.element = element;
        this.damage = damage;
    }

    public Element getElement() { return element; }
    public int getDamage() { return damage; }
}