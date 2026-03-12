import org.junit.platform.suite.api.SelectClasses;
import org.junit.platform.suite.api.Suite;

@SelectClasses({
    AdderTestSuite.AdderTest.class,
    AdderTestSuite.AdderInvalidTest.class,
})
@Suite
public class AdderTestSuite {
    @SelectClasses({
        math.operation.textual.AdderTest.class,
    })
    @Suite 
    public static class AdderTest {}

    
    @SelectClasses({
        math.operation.textual.AdderInvalidTest.class,
    })
    @Suite 
    public static class AdderInvalidTest {}
}