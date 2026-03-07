module Homework3 where

triangleSides :: Integer -> Integer -> Integer -> Bool
{-
a,b,c
True, ha
    a + b > c és a + c > b és b + c > a
-}
triangleSides a b c = a + b > c && a + c > b && b + c > a

isLeapYear :: Integer -> Bool
isLeapYear y = (y `mod` 400 == 0) || (y `mod` 4 == 0 && not (y `mod` 100 == 0))


sumTo :: Integer -> Integer
sumTo 0 = 0
sumTo n = n + sumTo (n - 1)
