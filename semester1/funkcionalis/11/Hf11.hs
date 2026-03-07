module Hs11 where

myAll :: (a -> Bool) -> [a]{-véges-} -> Bool
myAll _ [] = True
myAll p (x:xs)
    | p x       = myAll p xs
    | otherwise = False


filters :: Eq a => [a] -> [a] -> [a]
filters _ [] = []
filters fs (x:xs)
 | elem x fs = filters fs xs
 | otherwise = x : filters fs xs


compress :: Eq a => [a] -> [(a, Int)]
compress [] = []
compress ls@(x:xs) = (x, length a) : compress b
    where (a, b) = span (==x) ls


applyOnNeighbours :: (a -> a -> a) -> [a] -> [a]
applyOnNeighbours p ls@(x:xs) = zipWith p (x:xs) xs


myCurry :: ((a, b) -> c) -> (a -> b -> c) -- ((a, b) -> c) -> a -> b -> c
myCurry p x y = p (x, y)
