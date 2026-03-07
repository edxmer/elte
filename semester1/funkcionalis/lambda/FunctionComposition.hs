module FunctionComposition where


import Data.List
import Data.Char (isSpace)

notNull :: [a] -> Bool
notNull = not . null

myEven :: Integral a => a -> Bool
myEven = (0==) . (`mod` 2)

numbersMadeOfOnes :: [Integer]
numbersMadeOfOnes = iterate ((+1).(*10)) 1

numbersMadeOfThrees :: [Integer]
numbersMadeOfThrees = iterate ((+3) . (*10)) 3

dropSpaces :: String -> String
dropSpaces = dropWhile isSpace

trim :: String -> String
trim = reverse . dropSpaces . reverse . dropSpaces


firstLetters :: String -> String
firstLetters = unwords . map (take 1) . words


monogram :: String -> String
-- monogram = unwords . map ((++".") . (take 1)) . words
monogram = unwords . map ((:".") . head) . words

myUntil :: (a -> Bool) -> (a -> a) -> a -> a
myUntil t f = head . filter t . iterate f

uniq :: Ord a => [a] -> [a]
uniq = map head . group . sort

repeated :: Ord a => [a]{-véges-} -> [a]
repeated = map head . filter ((1<) . length) . group . sort

sublists = concat . map (filter (not . null)) . map tails . filter (not . null) . inits

mapFiltered :: (a -> Bool) -> (a -> b) -> [a] -> [b]
mapFiltered t f = (map f . filter t)

filterMapped :: (b -> Bool) -> (a -> b) -> [a] -> [b]
filterMapped t f = filter t . map f

numbersMadeOfThreesAndOne :: [Integer]
numbersMadeOfThreesAndOne = map ((+) (-2)) $ iterate ((+3) . (*10)) 3
-- numbersMadeOfThreesAndOne = map (subtract 2) $ iterate ((+3) . (*10)) 3

maximumOfMinimums :: Ord a => [[a]] -> Maybe a
maximumOfMinimums ls
 | (null ls) || (or $ map null ls) = Nothing
 | otherwise = Just (foldr1 max $ map (foldr1 min) ls)


subListWithLength :: Int -> [a] -> [[a]]
subListWithLength n = filter ((==n) . length) . sublists



numWithMostDiv :: Integral a => [a] -> a
numWithMostDiv ls = head $ filter ((==maxdivcount) . length . divisors) $ reverse $ sort ls
 where 
  maxdivcount = maximum (map (length . divisors) ls)
  divisors n = [ i | i <- [2..(n `div` 2)], n `mod` i == 0 ]

longestWord :: String -> String
longestWord = fst . foldr1 maxt2 . map (\x -> (x, length x)) . words
 where
  maxt2 (a1, a2) (b1, b2)
   | a2 >= b2  = (a1, a2)
   | otherwise = (b1, b2)

avgDistance :: Fractional a => [a] -> a
avgDistance = avg . map (\(x,y) -> abs (y-x)) . neighbors
 where
  avg ls = (sum ls) / (fromIntegral (length ls))
  neighbors (x:y:xs) = (x, y) : neighbors (y:xs)
  neighbors _        = []
