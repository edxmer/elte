union [ 
    union [rect 1 1  `move` (-4 + i, 4) | i <- [0,1..8]], 
    union [rect 1 1  `move` (-4 + i, -4) | i <- [0,1..8]], 
    union [rect 1 1  `move` (-4, -4 + i) | i <- [0,1..8]], 
    union [rect 1 1  `move` (4, -4 + i) | i <- [0,1..8]],

    union [rect 1 1  `move` (-2 + i, -2) | i <- [0,1..4]],
    rect 1 1 `move` (-2, -1),
    rect 1 1 `move` (2, -1),
    rect 1 1 `move` (-2, 1),
    rect 1 1 `move` (2, 1)
    ] `rotate` 10 `move` (-10, 1) `fill` rgb 0.851 0.655 0 `strokeWidth` 0

    <|>

    union [ 
        union [rect 1 1 `fill` black `move` (-4 + i, 4) | i <- [0,1..8]], 
        union [rect 1 1 `fill` black `move` (-4 + i, -4) | i <- [0,1..8]], 
        union [rect 1 1 `fill` black `move` (-4, -4 + i) | i <- [0,1..8]], 
        union [rect 1 1 `fill` black `move` (4, -4 + i) | i <- [0,1..8]],

        rect 0.5 3 `fill` rgb 0.478 0.686 0.91 `move` (-2, -0.5),
        rect 0.5 3 `fill` rgb 0.478 0.686 0.91 `move` (2, -0.5),

        union [rect 1 1 `fill` black `move` (-2 + i, - 1) | i <- [0,1..4]],

        rect 1 1 `fill` black `move` (-2, -2),
        rect 1 1 `fill` black `move` (2, -2),
        rect 1 0.5 `fill` black `move` (-2, 1),
        rect 1 0.5 `fill` black `move` (2, 1)
        ] `rotate` -14 `move` (10, -4) `strokeWidth` 0

<|>

union [ 
    union [rect 1 1  `move` (-4 + i, 4) | i <- [0,1..8]], 
    union [rect 1 1  `move` (-4 + i, -4) | i <- [0,1..8]], 
    union [rect 1 1  `move` (-4, -4 + i) | i <- [0,1..8]], 
    union [rect 1 1  `move` (4, -4 + i) | i <- [0,1..8]],
    
    rect 1 1 `move` (-1, -2),
    rect 1 1 `move` (1, -2),

    rect 1 1 `move` (-2, -1),
    rect 1 1 `move` (-2, -1),
    rect 1 1 `move` (2, -1),
    rect 1 1 `move` (0, -1),
    rect 1 1 `move` (-2, 1),
    rect 1 1 `move` (2, 1)
    ] `rotate` 2 `move` (0, -1) `fill` rgb 1 0.396 0.816 `strokeWidth` 0

