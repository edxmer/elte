
import myrpg.action.Attack;
import myrpg.character.BasicCharacter;
import myrpg.simulator.FightSimulator;

class Test {
    public static void main(String... args) {
        Attack at = new Attack("water", 30);
        IO.println("element: %s; damage: %d".formatted(at.getElement(), at.getDamage()));

        BasicCharacter bc = new BasicCharacter("Dave", "fire", "water", 100, 15);
        IO.println("name: %s; health: %s; isAlive: %b".formatted(bc.getName(), bc.getHealth(), bc.isAlive()));
        bc.takeDamage(at);
        IO.println("name: %s; health: %s; isAlive: %b".formatted(bc.getName(), bc.getHealth(), bc.isAlive()));
        bc.takeDamage(at);
        IO.println("name: %s; health: %s; isAlive: %b".formatted(bc.getName(), bc.getHealth(), bc.isAlive()));

        IO.println("-- o --");

        BasicCharacter c1 = new BasicCharacter("Dave", "fire", "coldfire", 100, 15);
        BasicCharacter c2 = new BasicCharacter("Cat", "coldfire", "water", 100, 15);
        FightSimulator.fight(c1, c2);

    }
}