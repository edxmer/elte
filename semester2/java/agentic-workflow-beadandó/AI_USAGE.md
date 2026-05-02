## Használt eszközök:
- Claude Sonnet 4.6

## 1. Feladat megismerése
  - Feltöltöttem Claude-nak az egész feladatleírást, majd megmondtam neki, hogy analizálja ezt a feladatot
  - ezután feltettem kérdéseket, pl. azzal kapcsolatban, hogy legvalószínűbben mit szeretnének hogy legyenek a segédfüggvényekben, hogy interaktív legyen, random, vagy hardkódolt
  * az adott válaszok alapján úgy döntöttem, hogy hardkódolt lenne a leglogikusabb
## 2. Strukturával kapcsolatos kérdések
  - Megkérdeztem, hogy a fájlstrukturában hova lenne a leglogikusabb létrehozni a osztályt
  * azt mondta, hogy `agentic/workflow/util/WorkflowFileWriter.java` helyre hozzam létre
## 3. Kód legenerálása
  - Megmondtam, hogy készítse el a teljes osztályt, 5 `private static void write...Agent(String filepath)` metódussal, különböző agentek generálására.
  * létrehozta az osztályt, viszont rengeteg ismétlődés volt benne, amit szerintem sokkal szebb lenne kiemelni egy `private static void writeStep(PrintWriter pw, String name, String prompt, String systemPrompt, String output)` metódusba.
  - megkértem, hogy javítsa ki, hogy készítse el és használja azt a metódust inkább.
  * az így megkapott kód máris sokkal szebb lett, kevesebb a kódismétlés. Ezt fogtam, és be is másoltam a `WorkflowFileWriter.java`-ba.
## 4. Kód kijavítása
  - Néha fura módon formatálta a kódot, ezért a kódszerkesztőm formatterével (Prettier) formattáltam a kódolt.
  - a `package`-t rosszul adta meg, ezt át kellett írnom.
## 5. Kód lefuttatása
  - Létrehoztam a `WorkflowFileWriterMain` osztályt, ahonnan meghívtam mindegyik metódust, hogy generáljon .agent fájlokat az `agent-examples/generated` mappába. Minden sikeresen lefutott, és helyesnek is tűntek a generált fájlok.
  - lefuttattam az összes .agent fájlt is, és minden teljesen helyesn működött.
