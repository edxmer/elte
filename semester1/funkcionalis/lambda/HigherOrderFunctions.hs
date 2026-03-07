module HigherOrderFunctions where


-- :t (> 0) -- operátor szelet
-- ((<) 4) 5
-- operátoroknál mi mondhatjuk meg, hogy melyik operandust fixáljuk
-- (1 +)
-- (+ 1)
-- Ha sima függvényt is szeretnénk így kezelni, akkor lehet `` közé tenni
--

{--

Általánosítás:

filter :: (a -> Bool) -> [a] -> [a]
filter p [] = []
filter p (x:xs)
  | p x       = x : filter p xs
  | otherwise = filter  p xs

--}

filterEvens :: Integral a => [a] -> [a]
filterEvens ls = filter even ls

filterPos :: Integral a => [a] -> [a]
filterPos ls = filter (>0) ls

{--

1. megoldás: neves függvények

filterOdds :: Integral a => [a] -> [a]
filterOdds ls = filter odd ls

filterPrimes :: Integral a => [a] -> [a]
filterPrimes ls = filter isPrime ls korábban megadtuk az isPrime függvényt


2. parciálisan alkalmazott függvény
:t (1 +) -- a bal oldali operandus rögzített, megfelel a szabályok szerinti sorrendnek: (+) 1
:t (+ 1) -- a jobb oldali operandus rögzített
:t (0 >) -- a jobb oldali operandust fogja helyettesíteni a paraméterként kapott értékkel : (>) 0
:t (> 0) -- a jobb oldali operandus rögzített
:t (`mod` 3) -- hárommal vett osztási maradékot előállító művelet



3. lambda függvények

\ x -> x + 1 -- (+ 1) operátor szelettel kifejezhető

\ x -> x ^ 2 -- (^ 2) operátor szelettel kifejezhető

\ x -> x `mod` 2 == 0 -- az even függvény megfelelője

\ x -> elem x [1..10] -- (`elem` [1..10]) kifejezés megfelelője

--}



myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter p (x:xs)
 | p x       = x : myFilter p xs
 | otherwise = myFilter p xs



myMap :: (a -> b) -> [a] -> [b]
myMap _ []     = []
myMap p (x:xs) = (p x) : myMap p xs


myTakeWhile :: (a -> Bool) -> [a] -> [a]
myTakeWhile _ [] = []
myTakeWhile p (x:xs)
 | p x       = x : myTakeWhile p xs
 | otherwise = []




myDropWhile :: (a -> Bool) -> [a] -> [a]
myDropWhile _ [] = []
myDropWhile p (x:xs)
 | p x = myDropWhile p xs
-- | otherwise = x : myDropWhile (\ _ -> False) xs
 | otherwise = x : xs



myIterate :: (a -> a) -> a -> [a]  
myIterate f e = e : (myIterate f (f e))


fibPairs :: [(Integer, Integer)]
fibPairs = iterate (\ (a, b) -> (b, a+b)) (0, 1)

myAny :: (a -> Bool) -> [a]{-véges-} -> Bool
myAny _ [] = False
myAny p (x:xs)
 | p x       = True
 | otherwise = myAny p xs




myElem :: Eq a => a -> [a]{-véges-} -> Bool
--myElem e ls = any (==e) ls
myElem e = any (==e) -- point free függvény




infixr 0 $: -- ez a $ operátor
($:) :: (a -> b) -> a -> b


($:) p x = p x


--A dollár operátort alapvetően zárójelpárokat kiváltására használjuk. De olyan esetben is használható, amikor több függvényt alkalmaznánk egy adott értékre, például:

mooooo=map ($ 10) [sqrt, (* 2), (^2)]


--FONTOS Figyeljünk oda az alkalmazásra, mert az 1 + sin (2 + 3) helyett nem írhatjuk hogy 1 + sin $ 2 + 3. Ez a következő hibás kifejezést adná: (1 + sin) (2 + 3).



myZipWith :: (a -> b -> c) -> [a] -> [b] -> [c]
myZipWith p (x:xs) (y:ys) = (p x y) : myZipWith p xs ys
myZipWith _ _ _ = []


{-
 A párok konstruktora teljesen megfelel zipWith paraméternek, így a zip egy lehetséges definíciója:
 zip = zipWith (,)
-}


{-
 span :: (a -> Bool) -> [a] -> ([a],[a])
span p []     = ([],[])
span p (x:xs)
  | p x       = (x:ys1,ys2)
  | otherwise = ([],x:xs)
  where
    (ys1,ys2) = span p xs

-}


myGroup :: Eq a => [a]{-véges-} -> [[a]]
myGroup [] = []
myGroup (x:xs) = a : myGroup b
 where
  (a, b) = span (==x) (x:xs)



{- Összefogó mintőval
myGroup [] = []
myGroup ls@(x:xs) = a : myGroup b
 where
  (a, b) = span (==x) ls
-}


count :: (a -> Bool) -> [a] -> Int
count p [] = 0
count p (x:xs)
 | p x       = 1 + count p xs
 | otherwise = count p xs


myAll :: (a -> Bool) -> [a]{-véges-} -> Bool
myAll p [] = True
myAll p (x:xs)
 | p x       = myAll p xs
 | otherwise = False


filters :: Eq a => [a] -> [a] -> [a]
filters _ [] = []
filters fs (x:xs)
 | elem x fs = filters fs xs
 | otherwise = x : filters fs xs


applyOnNeighbours :: (a -> a -> a) -> [a] -> [a]
applyOnNeighbours p ls@(x:xs) = zipWith p ls xs


pascalTriangle :: [[Integer]]
{--
pascalTriangle = [ph i | i<-[1..]]
 where
  zw (x:y:xs) = (x+y) : zw (y:xs)
  zw _ = [1]
  ph 1 = [1]
  ph n = 1 : zw ( ph (n-1) ) --}

pascalTriangle = iterate nextRow [1]
 where
  nextRow x = zipWith (+) ( 0 : x ) ( x ++ [0] )


compress :: Eq a => [a] -> [(a, Int)]
compress ls = map (\x -> (head x, length x)) (group ls)





decompress :: Eq a => [(a, Int)] -> [a]
{--
decompress [] = []
decompress ((e, c) : xs) = (take c $ repeat e) ++ (decompress xs) --}
decompress xs = [ x | (x, c) <- xs, _ <- [1..c]  ]


weightedSum :: Num a => [(a,a)] -> a
weightedSum []            = 0
weightedSum ( (x, w):xs ) = x*w + weightedSum xs


myUncurry :: (a -> b -> c) -> ((a, b) -> c) -- (a -> b -> c) -> (a, b) -> c
myUncurry f (x, y) = f x y


myCurry :: ((a, b) -> c) -> (a -> b -> c) -- ((a, b) -> c) -> a -> b -> c
myCurry f x y = f (x, y)


mySqrt :: Double -> Double
{--
mySqrt 0 = 0
mySqrt a = head $ dropWhile (\x -> abs(x*x-a) >= 1e-10) $ iterate (\x -> (x+a/x)/2) a
--}

mySqrt 0 = 0
mySqrt a = until isGood step a
 where
  isGood x = abs (x*x-a) < 1e-10
  step x = (x+a/x)/2
