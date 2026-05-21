package myrpg.character;

import java.lang.IllegalArgumentException;
import myrpg.action.Attack;
import myrpg.common.Element;

public class Mage extends BasicCharacter {
    // << fields >>
    private int mana;

    // << constructor >>
    public Mage(String name, Element element, Element weakness, int health, int attackPower, int mana) { 
        if (mana < 0) throw new IllegalArgumentException();
        this.mana = mana;
        super(name, element, weakness, health, attackPower); 
    }

    // << getters >>
    public int getMana() { return mana; }

    // << methods >>
    @Override
    public Attack attack() {
        if (mana > 0) {
            mana = Math.max(0, mana-10);
            return new Attack(getElement(), getAttackPower()*2);
        }
        else return super.attack();
    }
    
}