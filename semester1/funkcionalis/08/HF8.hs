module HF8 where

distantPairs :: [(Integer,Integer)] -> Int
distantPairs ls = length [ 1 | (a, b) <- ls, abs (a-b) >= 2  ]

countOfAs :: String -> Int
countOfAs str = length [ 1 | w <- words str, w == "az" ]

excludeSquares :: [Integer]
-- excludeSquares = [ i | i <- [1..], not (elem i [ j^2 | j <- [1..i] ]) ]
excludeSquares = concat [ [(i^2 +1)..((i+1)^2 -1)] | i <- [1..] ]



monthDay :: [(Integer, Integer)]
monthDay = [ (m, d) | m <- [1..12], d <- [1..(monthLens !! (fromIntegral m - 1))]]
 where monthLens = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


everyNth :: Integer -> [a] -> [a]
everyNth n ls = [ x  |  (x, y) <- zip ls (cycle [1..n]), y == 1 ]
