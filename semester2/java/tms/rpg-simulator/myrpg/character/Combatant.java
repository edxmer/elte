package myrpg.character;

import myrpg.action.Attack;

public interface Combatant {
    Attack attack();
    void takeDamage(Attack a);
    boolean isAlive();
    String getName();
    int getHealth();
}