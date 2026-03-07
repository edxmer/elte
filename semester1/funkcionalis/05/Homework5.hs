module Homework5 where

mountain :: Integer -> [Integer]
mountain n = [1 .. n] ++ [n-1, n-2 .. 1]


wave :: Integer -> [Integer]

wave n = [0 .. n] ++ [n-1, n-2 .. -n] ++ [-n+1 .. 0]