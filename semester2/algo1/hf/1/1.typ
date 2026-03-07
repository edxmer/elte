#set page(
  paper: "a4",
  margin: (x: 2.5cm, y: 2.5cm),
  header: align(right)[
    #set text(8pt, gray)
    Algoritmusok és Adatszerkezetek 1. | gyakorlat
  ],
)

#set text(
  font: "New Computer Modern",
  size: 11pt,
  lang: "hu"
)

// Címsor és adatok
#align(center)[
  #block(inset: 1em)[
    #text(16pt, weight: "bold")[1. Házi Feladat] \
    #v(0.5em)
    #text(12pt)[Algoritmusok és Adatszerkezetek 1.]
  ]
]

#grid(
  columns: (1fr, 1fr),
  align(left)[
    *Név:* Nagy Edömér Tamás \
    *Neptun:* CWQSKI
  ],
  align(right)[
    *Dátum:* #datetime.today().display("[year]. [month]. [day].")
  ]
)

#line(length: 100%, stroke: 0.5pt + gray)
#v(1em)

// --- Feladatok ---

== 1. Feladat
Mit számol ki a Legendre-algoritmus? Mi a műveletigénye $k$ függvényében?

#rect(width: 100%, stroke: 0.5pt + luma(200), inset: 10pt)[
  A $"Legrende"(a:RR, k:NN):RR$ algoritmus visszatérési értéke $a^k$,
  amit hatékonyan, $Theta(log(k))$ időkomplexitásban számol ki.
]

#v(2em)

== 2. Feladat
Adott egy $n$ hosszú, egész számokat tartalmazó tömb. Keressük a tömb azon szakaszát, melynek összege a lehető legnagyobb. Készítsünk minél hatékonyabb (lehetőleg $Theta(n)$-es) megoldást!

#rect(width: 100%, stroke: 0.5pt + luma(200), inset: 10pt)[
  A megoldásom:
  #align(center)[ #image("stuki.png", width: 50%) ]
  Időkomplexitás: $Theta(n)$
]
