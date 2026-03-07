module Homework4 where


validTime :: Integer -> Integer -> Bool
validTime h m
 | 0 <= h && h < 24 && 0 <= m && m < 60 = True
 | otherwise = False

sumBetween :: Integer -> Integer -> Integer
sumBetween n m
 | n == m = n
 | n < m = m + sumBetween n (m-1)
 | n > m = m + sumBetween n (m+1)

leibniz :: Integer -> Double
leibniz 1 = 4
leibniz n = leibniz (n-1) + ( ( (-1)^(n+1) ) / (2* (fromIntegral n) - 1) ) * 4
