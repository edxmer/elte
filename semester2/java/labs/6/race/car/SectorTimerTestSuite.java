// race/car/SectorTimerTestSuite.java
package race.car;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class SectorTimerTestSuite {

    @Test
    public void seemsGood1() {
        WrongSectorTimer1 timer = new WrongSectorTimer1(1, 2, 3);
        assertArrayEquals(new int[]{1, 2, 3}, timer.sectorTimes);
        assertEquals(3, timer.sectorTimes.length);
    }

    @Test
    public void setArrayElemsBreaksEncapsulation1() {
        WrongSectorTimer1 timer = new WrongSectorTimer1(1, 2, 3);
        timer.sectorTimes[0] = 99;
        assertEquals(99, timer.sectorTimes[0]);
        assertEquals(3, timer.sectorTimes.length);
    }

    @Test
    public void setArrayBreaksEncapsulation() {
        WrongSectorTimer1 timer = new WrongSectorTimer1(1, 2, 3);
        timer.sectorTimes = new int[]{10, 20};
        assertArrayEquals(new int[]{10, 20}, timer.sectorTimes);
        assertEquals(2, timer.sectorTimes.length);
    }

    @Test
    public void seemsGood2() {
        WrongSectorTimer2 timer = new WrongSectorTimer2(1, 2, 3);
        assertArrayEquals(new int[]{1, 2, 3}, timer.getSectorTimes());
    }

    @Test
    public void constructorBreaksEncapsulation() {
        int[] localArray = {1, 2, 3};
        WrongSectorTimer2 timer = new WrongSectorTimer2(localArray);
        localArray[0] = 99;
        assertEquals(99, timer.getSectorTime(0));
        assertEquals(3, timer.getSectorTimes().length);
    }

    @Test
    public void getterBreaksEncapsulation() {
        WrongSectorTimer2 timer = new WrongSectorTimer2(1, 2, 3);
        timer.getSectorTimes()[0] = 99;
        assertEquals(99, timer.getSectorTime(0));
        assertEquals(3, timer.getSectorTimes().length);
    }

    @Test
    public void setterBreaksEncapsulation() {
        WrongSectorTimer2 timer = new WrongSectorTimer2(1, 2, 3);
        int[] localArray = {4, 5, 6, 7};
        timer.setSectorTimes(localArray);
        localArray[0] = 99;
        assertEquals(99, timer.getSectorTime(0));
        assertEquals(4, timer.getSectorTimes().length);
    }

    @Test
    public void constructorEncapsulatesWell() {
        int[] localArray = {1, 2, 3};
        SectorTimer timer = new SectorTimer(localArray);
        localArray[0] = 99;
        assertEquals(1, timer.getSectorTime(0));
    }

    @Test
    public void getterEncapsulatesWell() {
        SectorTimer timer = new SectorTimer(1, 2, 3);
        timer.getSectorTimes()[0] = 99;
        assertEquals(1, timer.getSectorTime(0));
    }

    @Test
    public void setterEncapsulatesWell() {
        SectorTimer timer = new SectorTimer(1, 2, 3);
        int[] localArray = {4, 5, 6, 7};
        timer.setLapTimes(localArray);
        localArray[0] = 99;
        assertEquals(4, timer.getSectorTime(0));
    }
}