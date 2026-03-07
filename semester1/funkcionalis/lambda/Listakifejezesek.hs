module Listakifejezesek where

divisors :: Integer -> [Integer]
divisors n = [ i | i <- [1..n], n `mod` i == 0]




powersOf2 :: Int -> [Integer]
powersOf2 n = [ 2 ^ n | n <- [0..n] ]


oddEven :: Int -> [Bool]
oddEven n = [ i `mod` 2 == 0 | i <- [1..n] ]



myReplicate :: Int -> a -> [a]
myReplicate n e = [ e | _ <- [1..n] ]



powerOfTwo :: Integer -> Integer
powerOfTwo n = head [ 2^i | i <- [0..], 2^i > n ]


exponentOf2 :: Integer -> Integer
exponentOf2 n = head [ i | i <- [0..], 2^i > n ]


isPrime :: Integer -> Bool
--isPrime n = length [i | i <- [1..n], n `mod` i == 0] == 2
--isPrime n = [i | i <- [1..n], n `mod` i == 0] == [1, n]
isPrime n = divisors n == [1, n]



primesToN :: Integer -> [Integer]
primesToN n = [ i | i <- [1..n], divisors i == [1, i] ]





time :: [(Int, Int)]
time = [ (o, p) | o <- [0..23], p <- [0..59]]


dominoes :: Integer -> [(Integer, Integer)]
dominoes n = [ (i, j) | i <- [0..n], j <- [i..n] ]
-- vagy
-- dominoes n = [ (i, j) | i <- [0..n], j <- [0..n], j >= i ]

monotonousSeq :: Int -> [Int]
monotonousSeq n = [ i | i <- [1..n], _ <- [1..i]]


indexString :: [Char] -> [(Integer, Char)] -- String -> [(Integer, Char)]
indexString ls = zip [1..] ls

mountain :: Integer -> [Integer]
mountain 0 = []
mountain 1 = [1]
mountain n = [ n - abs i | i <- [(-n+1)..(n-1)], not (n-i < 2 )]

mountains :: Integer -> [Integer]
--mountains n = concat [mountain i | i <- [1..n]]
mountains n = [ j | i <- [1..n], j <- ([1..i]++[i-1,i-2..2]) ]

asteriskSeq :: String
asteriskSeq = unwords [ [ '*' | _ <- [1..i] ] | i <- [1..]]

numOfAs :: String -> Int
numOfAs s = length [1 | 'a' <- s]

countOfAs :: String -> Int
countOfAs str = length [1 | "az" <- words str]

-- fontos:
-- isPrime :: Integer -> Bool
-- isPrime n = divisors n == [1,n]
-- mert így működik a listák egyenlőségvizsgálata
-- eqLists :: Eq a => [a] -> [a] -> Bool
-- eqLists []     []     = True
-- eqLists (x:xs) (y:ys) = x == y && eqLists xs ys
-- eqLists _      _      = False

filterPrimes :: [Integer] -> [Integer]
filterPrimes ls = [ i | i <- ls, divisors i == [1, i]]

distantPairs :: [(Integer,Integer)] -> Int
distantPairs ls = length [1 | (p, q) <- ls, abs (p - q) >= 2]

excludeSquares :: [Integer]
excludeSquares = concat [ [ j | j <- [i*i+1..(i+1)*(i+1)-1] ] | i <- [1..]]

monthDay :: [(Integer, Integer)]
months = [31,28,31,30,31,30,31,31,30,31,30,31]
-- monthDay = [(m, d) | m <- [1..12], d <- [1..(months !! (fromIntegral m - 1))] ]
monthDay = [(m, d) | (m, days) <- zip [1..12] months, d <- [1..days]]

wave :: Integer -> [Integer]
wave n = [0..n] ++ [n-1,n-2 .. (-n)] ++ [1-n..(-1)]

waves :: Integer -> [Integer]
waves n = concat [wave i | i <- [1..n]]

everyNth :: Integer -> [a] -> [a]
everyNth n ls = [ a | (a, b) <- zip ls (cycle [1..n]), b == 1]

numOfArticles :: String -> Int
numOfArticles str = length [1 | w <- words str, w == "a" || w == "az" || w == "egy"]

approxPi :: Int -> Double
approxPi n = sum (take n [ 1 / ((2*i-1)*((-1)**(i+1))) | i <- [1.0,2.0..] ]) * 4




-- Rendezett n-esek


second :: (a, b) -> b
second (x, y) = y

swap :: (a, b) -> (b, a)
swap (x, y) = (y, x)

mirrorX :: (Integer, Integer) -> (Integer, Integer)
mirrorX (x, y) = (x, -y)

scale' :: Integer -> (Integer, Integer) -> (Integer, Integer)
scale' n (x, y) = (n*x, n*y)

mirrorP :: (Integer, Integer) -> (Integer, Integer) -> (Integer, Integer)
mirrorP (xp, yp) (x, y) = ( xp - (x-xp) , yp - (y-yp))

distance :: (Double, Double) -> (Double, Double) -> Double
distance (x1, y1) (x2, y2) = sqrt ((x1 - x2) ^^ 2 + (y1 - y2) ^^ 2)
