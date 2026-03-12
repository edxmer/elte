package music.fan;

import music.recording.Artist;

public class Fan {
    private final String name;
    public String getName() { return name; }

    private final Artist favourite;
    public Artist getFavourite() { return favourite; }

    private int moneySpent;
    public int getMoneySpent() { return moneySpent; }

    public Fan(String name, Artist favourite) {
        this.name = name;
        this.favourite = favourite;
    }

    public int buyMerchandise(int cost, Fan... friends) {
        int friendWithSameFavourite = 0;

        for (int i=0; i<friends.length; ++i) {
            if (favourite == friends[i].getFavourite()) {
                ++friendWithSameFavourite;
            }
        }

        if (2 < friendWithSameFavourite) {
            cost = cost * 9 / 10;
        }
        else if (0 < friendWithSameFavourite) {
            cost = cost * 8 / 10;
        }

        favourite.getLabel().gotIncome(cost*friendWithSameFavourite/2);
        moneySpent += cost;

        return cost;

    }

    public boolean favesAtSameLabel(Fan other) {
        return favourite == other.getFavourite();
    }

    public String toString1() {
        return "Fan " + name + " a kedvenc előadójánál (" + favourite.getName() +") " + moneySpent + " forintot költött.";
    }

    public String toString2() {
        return "Fan %s a kedvenc előadójánál (%s) %d forintot költött.".formatted(name, favourite.getName(), moneySpent)

    }

    public String toString3() {
        return String.format("Fan %s a kedvenc előadójánál (%s) %d forintot költött.", name, favourite.getName(), moneySpent);

    }

    public String toString4() {
        StringBuilder sb;
        sb.append("Fan ");
        sb.append(name);
        sb.append(" a kedvenc előadójánál (");
        sb.append(favourite.getName());
        sb.append(favourite.getName());
        sb.append(") ");
        sb.append(moneySpent);
        sb.append(" forintot költött.");
        return sb.toString()
    }

}