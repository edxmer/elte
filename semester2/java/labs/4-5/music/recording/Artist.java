package music.recording;

public class Artist {
    private final String name;
    public String getName() { return name; }

    private final RecordLabel label;
    public RecordLabel getLabel() { return label; }

    public Artist(String name, RecordLabel label) {
        this.name = name;
        this.label = label;
    }
}