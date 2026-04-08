package array.util;

import static org.junit.jupiter.api.Assertions.*;
import module org.junit.jupiter;

import static array.util.ArrayUtil.*;

public class ArrayUtilTest {
    @Test
    public void maxLength0() {
        int[] A = {};
        assertEquals(0, max(A));
        assertEquals(0, max2(A));
        assertEquals(0, max3(A));
        assertEquals(0, max4(A));
    }

    @ParameterizedTest
    @CsvSource("""
    0
    1
    123123
    -123123
    """)
    public void maxLength1(int x) {
        int[] A = {x};
        assertEquals(x, max(A));
        assertEquals(x, max2(A));
        assertEquals(x, max3(A));
        assertEquals(x, max4(A));
    }

    @ParameterizedTest
    @CsvSource("""
    0, 4
    1, 5
    123123, 123124
    -123123, 0
    -123123, -123
    """)
    public void maxLength2(int minvalue, int maxvalue) {
        int[] A = {minvalue, maxvalue};
        int[] B = {maxvalue, minvalue};
        assertEquals(maxvalue, max(A));
        assertEquals(maxvalue, max(B));
        assertEquals(maxvalue, max2(A));
        assertEquals(maxvalue, max2(B));
        assertEquals(maxvalue, max3(A));
        assertEquals(maxvalue, max3(B));
        assertEquals(maxvalue, max4(A));
        assertEquals(maxvalue, max4(B));
    }

    @Test
    public void minMaxTest0() {
        int[] A = {};
        assertArrayEquals(new int[] {0, 0}, minMax(A));
    }

    @ParameterizedTest
    @CsvSource("""
    10
    0
    -15
    """)
    public void minMaxTest1(int x) {
        int[] A = {x};
        assertArrayEquals(new int[] {x, x}, minMax(A));
    }

    @ParameterizedTest
    @CsvSource("""
    10, 15
    0, 15
    -15, 10
    -15, 0
    -100, -15
    0, 0
    15, 15
    -100, -100
    """)
    public void minMaxTest2(int minvalue, int maxvalue) {
        int[] A = {minvalue, maxvalue};
        int[] B = {maxvalue, minvalue};
        int[] expected = {minvalue, maxvalue};
        assertArrayEquals(expected, minMax(A));
        assertArrayEquals(expected, minMax(B));
    }
}