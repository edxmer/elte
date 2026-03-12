import check.*;
import static check.Use.*;

import module org.junit.jupiter;

@BeforeAll
public static void init() {
    // usedLang = Lang.EN; // uncomment to enforce the message language
    Use.theClass("action.user.MultiDimensionalPoint", withInterfaces("action.Scalable", "action.Undoable"))
       .that(hasUsualModifiers());
}

@Test
public void fieldCoordinates() {
    it.hasField("coordinates: array of int")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER);
}

@Test
public void fieldLastCoordinates() {
    it.hasField("lastCoordinates: array of int")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER);
}

@Test
public void constructor() {
    it.hasConstructor(withArgsLikeFields("coordinates"))
      .thatIs(VISIBLE_TO_ALL);
}

@Test
public void methodGet() {
    it.hasMethod("get", withParams("idx: int"))
      .that(hasUsualModifiers())
      .thatReturns("int");
}

@Test
public void methodSet() {
    it.hasMethod("set", withParams("idx: int", "value: int"))
      .that(hasUsualModifiers())
      .thatReturnsNothing();
}

@Test
public void methodScale() {
    it.hasMethod("scale", withParams("factor: int"))
      .that(hasUsualModifiers())
      .thatReturnsNothing();
}

@Test
public void methodSaveToLast() {
    it.hasMethod("saveToLast", withNoParams())
      .thatIs(INSTANCE_LEVEL, FULLY_IMPLEMENTED, MODIFIABLE, VISIBLE_TO_NONE)
      .thatReturnsNothing();
}

@Test
public void methodUndoLast() {
    it.hasMethod("undoLast", withNoParams())
      .that(hasUsualModifiers())
      .thatReturnsNothing();
}

@Test
public void eq() {
    it.has(EQUALITY_CHECK);
}

@Test
public void text() {
    it.has(TEXTUAL_REPRESENTATION);
}

@Test
public void ordering() {
    it.has(NATURAL_ORDERING);
}

void main() {}


