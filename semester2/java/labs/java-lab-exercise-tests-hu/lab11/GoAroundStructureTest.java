import check.*;
import static check.Use.*;

import module org.junit.jupiter;

@BeforeAll
public static void init() {
    // usedLang = Lang.EN; // uncomment to enforce the message language
    Use.withTypeArg("T")
       .theClass("loop.GoAround", withInterface("Iterable of T"))
       .that(hasUsualModifiers());
}

@Test
public void fieldRoundCount() {
    it.hasField("roundCount: int")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER)
      .info("egy szerkezet, amely egy listányi elemet tárol, és azokat roundCount-szor sorban visszaadja")
      .info("a konstruktorban adjuk meg a körök számát és a tárolandó elemeket")
      .info("az iterator gondoskodik arról, hogy az elemeket pontosan roundCount alkalommal járjuk végig")
      .info("@param roundCount megadja, hogy hányszor kell a teljes elemlistát bejárni")
      .info("@param elements a tárolandó elemek listája");
}

@Test
public void fieldElements() {
    it.hasField("elements: List of T")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER);
}

@Test
public void constructor() {
    it.hasConstructor(withParams("roundCount: int", "elements: array of T"))
      .thatIs(VISIBLE_TO_ALL);
}

@Test
public void methodIterator() {
    it.hasMethod("iterator", withNoParams())
      .that(hasUsualModifiers())
      .thatReturns("GoAroundIterator of T");
}

void main() {}


