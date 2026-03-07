module AlgebraiAdattipus where

{-
data Answer = No | Maybe | Yes

toString :: Answer -> String
toString No = "No"
toString Maybe = "Maybe"
toString Yes = "Yes"
-}


data Pair = P Int Int

addElems :: Pair -> Int
addElems (P x y) = x + y

data Answer = No | Maybe | Yes deriving (Show, Eq)



data Day = Mon | Tue | Wed | Thu | Fri | Sat | Sun deriving (Show, Eq, Enum)

isWeekend :: Day -> Bool
isWeekend Sat = True
isWeekend Sun = True
isWeekend _ = False


tomorrow :: Day -> Day
tomorrow Mon = Tue
tomorrow Tue = Wed
tomorrow Wed = Thu
tomorrow Thu = Fri
tomorrow Fri = Sat
tomorrow Sat = Sun
tomorrow Sun = Mon


betterTomorrow :: Day -> Day
betterTomorrow Sun = Mon
betterTomorrow x = succ x




--data USTime = AM Int Int | PM Int Int deriving (Eq, Show)

showUSTime :: USTime -> String
showUSTime (AM x y) = showZero x ++ "." ++ showZero y ++ " am"
showUSTime (PM x y) = showZero x ++ "." ++ showZero y ++ " pm"

showZero :: Int -> String
showZero x
 | x < 10    = '0' : show x
 | otherwise = show x

-- Manuális példányosítás:
-- Ha kértünk automatikusat, nem lehet
data USTime = AM Int Int | PM Int Int

-- Eq-nál elegendő vagy a (==)-t vagy a (/=) függvényt példányosítani, a másik adódik a definícióból
instance Eq USTime where
    (==) (AM h1 m1) (AM h2 m2) = h1 == h2 && m1 == m2
    (==) (PM h1 m1) (PM h2 m2) = h1 == h2 && m1 == m2
    (==) _          _          = False

-- Ord-nál elegendő vagy a (<=) vagy a compare függvény példányosítása
instance Ord USTime where
    (<=) t1 t2 = toMinutes t1 <= toMinutes t2
        where
            toMinutes (AM 12 m) = m 
            toMinutes (AM h  m) = h*60 + m
            toMinutes (PM h  m) = (h + 12)*60 + m


data CardinalPoint = North | East | South | West deriving (Show, Eq)

turnLeft :: CardinalPoint -> CardinalPoint
turnLeft North = West
turnLeft West = South
turnLeft South = East
turnLeft East = North


turnRight :: CardinalPoint -> CardinalPoint
turnRight d = turnLeft (turnLeft (turnLeft d))


turnBack :: CardinalPoint -> CardinalPoint
turnBack d = turnLeft (turnLeft d)



yesterday :: Day -> Day
yesterday Mon = Sun
yesterday d = pred d


workdays :: [Day] -> [Day]
workdays (x:xs)
    | isWeekend x = workdays xs
    | otherwise   = x : workdays xs
workdays _ = []



betterShowUSTime :: USTime -> String
betterShowUSTime (AM x y) = showZero x ++ "." ++ showZero y ++ " am"
betterShowUSTime (PM x y) = showZero x ++ "." ++ showZero y ++ " pm"





data Time = T Int Int deriving (Show, Eq)

time2USTime :: Time -> USTime
time2USTime (T 12 m) = PM 12 m
time2USTime (T h m)
    | h < 12    = AM h m
    | otherwise = PM (h-12) m

uSTime2Time :: USTime -> Time 
uSTime2Time (PM 12 m) = T 12     m
uSTime2Time (AM h m)  = T h      m
uSTime2Time (PM h m)  = T (h+12) m



data MyRational = R Integer Integer deriving (Show)

simpleAdd :: MyRational -> MyRational -> MyRational
simpleAdd (R n1 d1) (R n2 d2) = R (n1*d2+n2*d1) (d1*d2)

simpleMult :: MyRational -> MyRational -> MyRational
simpleMult (R n1 d1) (R n2 d2) = R (n1*n2) (d1*d2)



{-
myGCD :: Integer -> Integer -> Integer
myGCD 0 x = x
myGCD x 0 = x
myGCD x y
    | x < 0 || y < 0 = myGCD (abs x) (abs y)
    | x > y     = myGCD (x-y) y
    | x < y     = myGCD x (y-x)
    | otherwise = x
-}

myGCD :: Integer -> Integer -> Integer
myGCD 0 x = x
myGCD x 0 = x
myGCD x y = hGCD (abs x) (abs y)
    where
        hGCD :: Integer -> Integer -> Integer
        hGCD x y
            | x > y     = myGCD (x `rem` y) y
            | x < y     = myGCD x (y `rem` x)
            | otherwise = x

simplify :: MyRational -> MyRational
simplify (R n d) = R (n `div` rgcd) (d `div` rgcd)
    where
        rgcd = myGCD n d


add  :: MyRational -> MyRational -> MyRational
mult :: MyRational -> MyRational -> MyRational
add x y  = simplify (simpleAdd x y)
mult x y = simplify (simpleMult x y)

instance Eq MyRational
    where
        (==) x y = n1 == n2 && d1 == d2
            where
                (R n1 d1) = normaliseNeg ( simplify x )
                (R n2 d2) = normaliseNeg ( simplify y )
                normaliseNeg (R n d)
                    | d < 0     = ( R (-n) (-d) )
                    | otherwise = (R n d)

