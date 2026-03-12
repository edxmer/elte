package music.recording;

public class RecordLabel {

    private final String name;
    public String getName() { return name; }

    private int cash;
    public int getCash() { return cash; }

    public RecordLabel(String name, int netWorth) {
        this.name = name;
        this.cash = netWorth;
    }

    public void gotIncome(int sum) {
        cash += sum;
    }

}