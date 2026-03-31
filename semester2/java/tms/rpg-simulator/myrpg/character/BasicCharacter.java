package myrpg.character;

import myrpg.action.Attack;

public class BasicCharacter {
    private String name;
    private String element;
    private String weakness;
    private int health;
    private int maxHealth;
    private int attackPower;

    // << constructor >>
    public BasicCharacter(String name, String element, String weakness, int health, int attackPower) {
        if (health < 0 || attackPower < 0) throw new IllegalArgumentException("Health and attackPower must be non-negative.");
    
        this.name = name;
        this.element = element;
        this.weakness = weakness;
        this.health = health;
        maxHealth = health;
        this.attackPower = attackPower;
    }

    // << getters >>
    public String   getName()   { return name; }
    public int      getHealth() { return health; }
    public boolean  isAlive()   { return 0 < health; }

    // << methods >>
    public Attack attack() {
        if (health*5 <= maxHealth) return new Attack(element, attackPower*2);
        return new Attack(element, attackPower);
    }

    public void takeDamage(Attack a) {
        if      (element.equals(a.getElement()))    {}
        else if (weakness.equals(a.getElement()))   { health -= a.getDamage() * 2; }
        else                                        { health -= a.getDamage(); }
    }

}