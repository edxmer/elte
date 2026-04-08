package election;



import election.candidate.Candidate;

public class Election {
    private int[] voteCounts;

    public Election() {
        int len = Candidate.values().length;
        voteCounts = new int[len];
        for (int i=0; i<len; ++i) { voteCounts[i] = 0; }
    }

    public void addVote(Candidate candidate) {
        voteCounts[candidate.ordinal()]++;
    }

    public void addVotes(Candidate candidate, int count) {
        voteCounts[candidate.ordinal()] += count;
    }

    public Candidate getWinner() {
        return Candidate.values()[getWinningIdx()];
    }


    public Candidate[] getCandidatesWithMoreVotesThan(int voteCount) {
        int count = getCandidateCountWithMoreVotesThan(voteCount);

        Candidate[] values = Candidate.values();

        Candidate[] out = new Candidate[count];
        int j=0;
        for (int i=0; i<voteCounts.length; ++i) {
            if (voteCount < voteCounts[i]) out[j++] = values[i];
        }

        return out;
    }

    private int getCandidateCountWithMoreVotesThan(int voteCount) {
        int count = 0;
        for (int i=0; i<voteCounts.length; ++i) {
            if (voteCount < voteCounts[i]) ++count;
        }
        return count;
    }

    private int getWinningIdx() {
        int idx = 0;
        int best = voteCounts[0];

        for (int i=1; i<voteCounts.length; ++i) {
            if (best < voteCounts[i]) {
                idx = i;
                best = voteCounts[i];
            }
        }

        return idx;
    }

}