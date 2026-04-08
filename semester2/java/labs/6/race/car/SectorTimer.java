package race.car;

public class SectorTimer {
    int[] sectorTimes;

    public SectorTimer(int... sectorTimes) {
        initSectorTimes(sectorTimes);
    }

    public SectorTimer(boolean fake, int... sectorTimes) {
        this.sectorTimes = new int[sectorTimes.length];
        System.arraycopy(sectorTimes, 0, this.sectorTimes, 0, sectorTimes.length);
    }

    private void initSectorTimes(int[] sectorTimes) {
        if (sectorTimes == null) {
            this.sectorTimes = new int[0];
            return;
        }

        this.sectorTimes = new int[sectorTimes.length];
        for (int i=0; i<sectorTimes.length; ++i) {
            this.sectorTimes[i] = sectorTimes[i];
        }
    }

    public int[] getSectorTimes() {
        int[] arr = new int[sectorTimes.length];
        for (int i=0; i<sectorTimes.length; ++i) {
            arr[i] = sectorTimes[i];
        }
        return arr;
    }

    public int[] getSectorTimesV2() {
        int[] arr = new int[sectorTimes.length];
        System.arraycopy(sectorTimes, 0, arr, 0, sectorTimes.length);
        return arr;
    }

    public int getSectorTime(int idx) {
        return sectorTimes[idx];
    }

    public void setLapTimes(int... sectorTimes) {
        initSectorTimes(sectorTimes);
    }


}