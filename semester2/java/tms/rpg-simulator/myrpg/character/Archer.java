package myrpg.character;

import java.lang.IllegalArgumentException;
import myrpg.action.Attack;
import myrpg.common.Element;

public class Archer extends BasicCharacter {
    // << fields >>
    private int precision;

    // << constructor >>
    public Archer(String name, Element element, Element weakness, int health, int attackPower, int precision) { 
        if (precision < 0 || 100 < precision) throw new IllegalArgumentException();
        this.precision = precision;
        super(name, element, weakness, health, attackPower); 
    }

    // << getters >>
    public int getPrecision() { return precision; }

    // << methods >>
    @Override
    public Attack attack() {
        int damage = ((getHealth()*5 <= getMaxHealth()) ? getAttackPower() * 2 : getAttackPower()) + precision / 10;
        return new Attack(getElement(), damage);
    }
    
}