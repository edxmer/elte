module T where


seged :: Integer -> Integer -> Double -> Double -> Double
seged n i nev elo
 | i <= n = elo/nev + seged n (i+1) (nev+2) (-elo)
 | otherwise = 0

leibniz :: Integer -> Double
leibniz n = 4 * (seged n 1 1.0 1.0)