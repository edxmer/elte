package myrpg.simulator;

import myrpg.character.BasicCharacter;

public class FightSimulator {

    public static void fight(BasicCharacter c1, BasicCharacter c2, int limit) {
        for (int i=1; i<=limit; ++i) {
            // c1 attack c2
            c2.takeDamage(c1.attack());
            if (!c2.isAlive()) return;
            // c2 attack c1
            c1.takeDamage(c2.attack());
            if (!c1.isAlive()) return;
        }
    }

    public static void fight(BasicCharacter c1, BasicCharacter c2) { fight(c1, c2, 10); }
}