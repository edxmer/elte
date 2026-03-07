module Zh where

import Data.Char (isLower, toUpper)

doubleTriple :: [a] -> [a]
doubleTriple (x:[]) = [x,x,x]
doubleTriple (x:y:[]) = [x,x,y,y]
doubleTriple ls = ls



lengthOfShorter :: [a] -> [b] -> Integer
lengthOfShorter [] _ = 0
lengthOfShorter _ [] = 0
lengthOfShorter (x:xs) (y:ys) = 1 + lengthOfShorter xs ys




compressLetters :: String -> String
compressLetters [] = []
compressLetters (x:[]) = [x]
compressLetters (x:y:xs)
 | x == y && isLower x && isLower y = toUpper x : compressLetters xs
 | otherwise = x : compressLetters (y:xs)

