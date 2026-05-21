package myrpg.simulator;

import myrpg.team.Team;
import myrpg.character.BasicCharacter;

public class TeamFightSimulator {

    public static Team fight(Team t1, Team t2, int limit) {
        for (int i=0; i<limit; ++i) {
            BasicCharacter t1strongest = t1.getStrongestMember();
            BasicCharacter t2strongest = t2.getStrongestMember();
            
            // t1 strongest attack t2 strongest
            t2strongest.takeDamage(
                t1strongest.attack()
            );
            
            // if t2 strongest is still alive, attack t1
            if (t2strongest.isAlive()) {
                t1strongest.takeDamage(
                    t2strongest.attack()
                );
            }

            // check if there is a winner
            if (t1.hasLost()) return t2;
            if (t2.hasLost()) return t1;
        }
        return null;
    }

    public static Team fight(Team t1, Team t2) { return fight(t1, t2, 100); }
}