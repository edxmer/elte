module HF7 where

isLongerThan :: [a] -> Integer -> Bool
isLongerThan [] n | n > 0 = False
isLongerThan _ n | n <= 0 = True
isLongerThan (x:xs) n = isLongerThan xs (n-1)


injectElem :: a -> [a] -> [a]
injectElem e [] = []
injectElem e (x:[]) = [x]
injectElem e (x:xs) = x:e:injectElem e xs

ordInsert :: Ord a => a -> [a] -> [a]
ordInsert e [] = [e]
ordInsert e (x:xs)
 | e <= x = e:x:xs
 | otherwise = x : ordInsert e xs


myEnumFromThenTo :: Integer -> Integer -> Integer -> [Integer]
myEnumFromThenTo f s l
 | f <= s && f > l = []
 | f > s && f < l = []
 | otherwise = f : myEnumFromThenTo s (s+s-f) l


sortedMerge :: Ord a => [a] -> [a] -> [a]
sortedMerge [] [] = []
sortedMerge [] l = l
sortedMerge l [] = l
sortedMerge (x:xs) (y:ys)
 | x < y = x : sortedMerge xs (y:ys)
 | otherwise = y : sortedMerge (x:xs) ys