module Homework2 where

signOfHead :: [Integer] -> Integer
signOfHead (x:_)
    | 0 < x = 1
    | x == 0 = 0
    | otherwise = -1

range :: [Integer] -> [Integer]
range [] = []
range (x:[]) = [x..]
range (x:y:[]) = [x,y..]
range (x:y:z:_) = [x,y..z]

elimElem :: Eq a => a -> [a] -> [a]
elimElem e [] = []
elimElem e (x:xs)
    | e == x = elimElem e xs
    | otherwise = x : elimElem e xs

myReplicate :: Int -> a -> [a]
myReplicate 0 e = []
myReplicate n e = e : myReplicate (n-1) e