import check.*;
import static check.Use.*;

import module org.junit.jupiter;

@BeforeAll
public static void init() {
    // usedLang = Lang.EN; // uncomment to enforce the message language
    Use.withTypeArg("T")
       .theClass("loop.iterator.GoAroundIterator", withInterface("Iterator of T"))
       .thatIs(INSTANCE_LEVEL, FULLY_IMPLEMENTED, NOT_MODIFIABLE, VISIBLE_TO_ALL)
       .info("olyan bejáró, amely egy lista elemeit `roundCount` alkalommal adja vissza")
       .info("belső számlálóval (idx) lépkedünk végig az elemek között; ha a lista végére érünk, új kört kezdünk");
}

@Test
public void fieldIdx() {
    it.hasField("idx: int")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER);
}

@Test
public void fieldRound() {
    it.hasField("round: int")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER)
      .info("számon tartja, hány teljes kört tettünk már meg");
}

@Test
public void fieldRoundCount() {
    it.hasField("roundCount: int")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER);
}

@Test
public void fieldElements() {
    it.hasField("elements: List of T")
      .that(hasUsualModifiers())
      .thatHasNo(GETTER, SETTER);
}

@Test
public void constructor() {
    it.hasConstructor(withArgsLikeFields("roundCount", "elements"))
      .thatIs(VISIBLE_TO_ALL);
}

@Test
public void methodHasNext() {
    it.hasMethod("hasNext", withNoParams())
      .that(hasUsualModifiers())
      .thatReturns("boolean")
      .info("addig ad igazat, amíg a teljesített körök száma kisebb, mint `roundCount`");
}

@Test
public void methodNext() {
    it.hasMethod("next", withNoParams())
      .that(hasUsualModifiers())
      .thatReturns("T")
      .info("visszaadja az aktuális elemet, majd előrelépteti az indexet; ha új kör indul, növeli a `round` értékét");
}

void main() {}


