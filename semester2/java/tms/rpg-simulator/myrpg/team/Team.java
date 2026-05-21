package myrpg.team;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;
import java.util.HashSet;
import myrpg.character.BasicCharacter;
import myrpg.common.Element;

public class Team {
    // << fields >>
    private String name;
    private ArrayList<BasicCharacter> members;

    // << Constructor >>
    public Team(String name) {
        this.name = name;
        members = new ArrayList<BasicCharacter>();
    }

    // << getters >>
    public String getName() { return name; }

    public List<BasicCharacter> getAliveMembers() {
        ArrayList<BasicCharacter> aliveMembers = new ArrayList<BasicCharacter>();
        for (BasicCharacter c : members) {
            if (c.isAlive()) aliveMembers.add(c);
        }
        return aliveMembers;
    }

    public BasicCharacter getStrongestMember() {
        BasicCharacter max = null;
        int maxValue = 0;
        for (BasicCharacter c : members) {
            if (maxValue < c.getHealth()) {
                maxValue = c.getHealth();
                max = c;
            }
        }
        return max;
    }
    
    // << methods >>
    public void addMemeber(BasicCharacter c) {
        members.add(c);
    }

    public boolean hasLost() {
        for (BasicCharacter c : members) {
            if (c.isAlive()) return false;
        }
        return true;
    }

    public Set<Element> getElements() {
        HashSet<Element> elements = new HashSet<Element>();
        for (BasicCharacter c : members) {
            if (c.isAlive()) elements.add(c.getElement());
        }
        return elements;
    }
}