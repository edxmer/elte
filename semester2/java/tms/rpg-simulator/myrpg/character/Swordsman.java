package myrpg.character;

import java.lang.IllegalArgumentException;
import myrpg.action.Attack;
import myrpg.common.Element;

public class Swordsman extends BasicCharacter {
    // << fields >>
    private int armor;

    // << constructor >>
    public Swordsman(String name, Element element, Element weakness, int health, int attackPower, int armor) { 
        if (armor < 0) throw new IllegalArgumentException();
        this.armor = armor;
        super(name, element, weakness, health, attackPower); 
    }

    // << getters >>
    public int getArmor() { return armor; }

    // << methods >>
    @Override
    public void takeDamage(Attack a) {
        int effectiveDamage = 0;
        if      (getElement().equals(a.getElement()))  {}
        else if (getWeakness().equals(a.getElement())) {
            effectiveDamage = a.getDamage() * 2;
        }
        else {
            effectiveDamage = a.getDamage();
        }
        effectiveDamage = Math.max(0, effectiveDamage - armor);
        reduceHealth(effectiveDamage);
    }
    
}