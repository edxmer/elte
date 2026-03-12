import check.*;
import static check.Use.*;

import module org.junit.jupiter;

@BeforeAll
public static void init() {
    // usedLang = Lang.EN; // uncomment to enforce the message language
    Use.theInterface("action.Undoable")
       .thatIs(INSTANCE_LEVEL, NOT_IMPLEMENTED, MODIFIABLE, VISIBLE_TO_ALL);
}

@Test
public void methodUndoLast() {
    it.hasMethod("undoLast", withNoParams())
      .that(hasUsualModifiers())
      .thatReturnsNothing();
}

void main() {}


