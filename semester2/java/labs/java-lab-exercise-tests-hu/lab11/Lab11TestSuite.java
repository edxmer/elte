import org.junit.platform.suite.api.*;
import org.junit.jupiter.api.*;

@SelectClasses({
    Lab11TestSuite.StructuralTests.class,
    Lab11TestSuite.FunctionalTests.class,
})
@Suite(failIfNoTests=false) public class Lab11TestSuite {
    @SelectClasses({
        UndoableStructureTest.class,
        ScalableStructureTest.class,
        MultiDimensionalPointStructureTest.class,
        GoAroundStructureTest.class,
        GoAroundIteratorStructureTest.class,
    })
    @Suite(failIfNoTests=false) @Tag("structural") public static class StructuralTests {}

    @SelectClasses({
        action.user.MultiDimensionalPointTest.class,
        loop.GoAroundTest.class,
        loop.iterator.GoAroundIteratorTest.class,
    })
    @Suite(failIfNoTests=false) @Tag("functional") public static class FunctionalTests {}
}

