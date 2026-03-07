module List1x1 where

dupElems :: [a] -> [a]
dupElems [] = []
dupElems (x:xs) = x : x : dupElems xs


dupEverySnd :: [a] -> [a]
dupEverySnd []       = []
dupEverySnd (x:[])   = [x]
dupEverySnd (x:y:xs) = x : y : y : dupEverySnd xs


neighbourDiff :: Num a => [a] -> [a]
neighbourDiff [] = []
neighbourDiff (_:[]) = []
neighbourDiff (x:y:xs) = (y-x) : neighbourDiff (y:xs)


isIncreasing :: [Integer] -> Bool
isIncreasing []     = True
isIncreasing (_:[]) = True
isIncreasing (x:y:xs)
 | x < y     = isIncreasing (y:xs)
 | otherwise = False


addElems :: Num a => [a] -> [a] -> [a]
addElems [] [] = []
addElems [] _  = []
addElems _ []  = []
addElems (x:xs) (y:ys) = (x+y) : addElems xs ys


divisors :: Integer -> [Integer]
divisors n | n <= 0 = []
divisors n          = [i |
                       i <- [1..n],
                       n `mod` i == 0]


