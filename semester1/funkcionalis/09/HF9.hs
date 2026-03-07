module HF9 where


data USTime = AM Int Int | PM Int Int deriving (Eq, Show)


data CardinalPoint = North | East | South | West deriving (Eq, Show)

numOfDirection :: CardinalPoint -> [CardinalPoint] -> Integer
numOfDirection _ [] = 0
numOfDirection d (x:xs)
    | d == x    = 1 + numOfDirection d xs0
    | otherwise = 0 + numOfDirection d xs


turnLeft :: CardinalPoint -> CardinalPoint
turnLeft North = West
turnLeft West  = South
turnLeft South = East
turnLeft East  = North

data Time = T Int Int deriving (Eq, Show)

time2USTime :: Time -> USTime
time2USTime (T 12 m) = PM 12 m
time2USTime (T h m)
    | h < 12    = AM h m
    | otherwise = PM (h-12) m

uSTime2Time :: USTime -> Time 
uSTime2Time (PM 12 m) = T 12     m
uSTime2Time (AM h m)  = T h      m
uSTime2Time (PM h m)  = T (h+12) m
