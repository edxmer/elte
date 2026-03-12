import check.*;
import static check.Use.*;

import module org.junit.jupiter;

@BeforeAll
public static void init() {
    // usedLang = Lang.EN; // uncomment to enforce the message language
    Use.theInterface("action.Scalable")
       .thatIs(INSTANCE_LEVEL, NOT_IMPLEMENTED, MODIFIABLE, VISIBLE_TO_ALL);
}

@Test
public void methodScale() {
    it.hasMethod("scale", withParams("factor: int"))
      .that(hasUsualModifiers())
      .thatReturnsNothing();
}

void main() {}


