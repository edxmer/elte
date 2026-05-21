package myrpg.character;

import myrpg.common.Element;
import myrpg.action.Attack;

public class BasicCharacter implements Combatant {
    private String name;
    private Element element, weakness;
    private int maxHealth, attackPower;
    private int health;

    // << constructor >>
    public BasicCharacter(String name, Element element, Element weakness, int health, int attackPower) {
        if (health < 0 || attackPower < 0) throw new IllegalArgumentException("Health and attackPower must be non-negative.");
        
        this.name = name;
        this.element = element;
        this.weakness = weakness;
        this.health = health;
        maxHealth = health;
        this.attackPower = attackPower;
    }

    // << getters >>
    public    String    getName()           { return name; }
    public    int       getHealth()         { return health; }
    public    boolean   isAlive()           { return 0 < health; }
    public    Element   getElement()        { return element; }
    public    Element   getWeakness()       { return weakness; }
    protected int       getMaxHealth()      { return maxHealth; }
    protected int       getAttackPower()    { return attackPower; }

    // << methods >>
    public Attack attack() {
        int damage = (health*5 <= maxHealth) ? attackPower*2 : attackPower;
        return new Attack(element, damage);
    }

    public void takeDamage(Attack a) {
        if      (element.equals(a.getElement()))    {}
        else if (weakness.equals(a.getElement()))   { health -= a.getDamage() * 2; }
        else                                        { health -= a.getDamage(); }
    }

    protected void reduceHealth(int amount) {
        health -= amount;
    }

}