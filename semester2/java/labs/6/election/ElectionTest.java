package election;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

import static array.util.ArrayUtil.*;

import election.Election;
import election.candidate.Candidate;

public class ElectionTest {

    public ElectionTest() {}

    @Test
    public void noVotes() {
        Election election = new Election();

        assertEquals(Candidate.JACK, election.getWinner());
    }

    @ParameterizedTest
    @CsvSource("""
    JACK, 1
    JILL, 10
    SAM, 100
    MAX, 10000
    """)
    public void singleCandidate(Candidate candidate, int voteCount) {
        Election election = new Election();

        election.addVotes(candidate, voteCount);

        assertEquals(candidate, election.getWinner());
    }

    @ParameterizedTest
    @CsvSource("""
    JACK, JILL, 1
    JILL, SAM, 10
    SAM, MAX, 100
    JACK, MAX, 10000
    """)
    public void twoCandidatesSameVoteCount(Candidate c1, Candidate c2, int voteCount) {
        Election election = new Election();

        election.addVotes(c1, voteCount);
        election.addVotes(c2, voteCount);

        assertEquals(c1, election.getWinner());
    }

    @ParameterizedTest
    @CsvSource("""
    JACK,JILL,SAM,MAX
    JILL,SAM,MAX,JACK
    SAM,MAX,JACK,JILL
    MAX,JACK,JILL,SAM
    """)
    public void candidateVoteCount(Candidate c1, Candidate c2, Candidate c3, Candidate c4) {
        Election election = new Election();

        election.addVotes(c1, 1);
        election.addVotes(c2, 4);
        election.addVotes(c3, 3);
        election.addVotes(c4, 2);

        assertEquals(c2, election.getWinner());
    
        assertArrayEquals(new Candidate[] {c2}, election.getCandidatesWithMoreVotesThan(3) );
    }





}