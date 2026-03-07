module AdditionalHigherOrderFunctions where

import Data.List

myAnd :: [Bool] -> Bool
myAnd = foldr (&&) True


myMaximum :: Ord a => [a] -> a
-- myMaximum (x:xs) = foldl max x xs
myMaximum = foldl1 max


myFlip :: (a -> b -> c) -> (b -> a -> c)
myFlip f x y = f y x
-- myFlip f = (\x y -> f y x)

myOn :: (b -> b -> c) -> (a -> b) -> (a -> a -> c)
myOn f g x y =  f (g x) (g y)
-- myOn f g = (\x y -> f (g x) (g y))
-- myOn f g = (\x y-> g x `f` g y)

numbersInString :: String -> [String]
numbersInString = filter (isDigit . head) . groupBy (\x y -> isDigit x && isDigit y)

longestWord :: String -> String
longestWord = maximumBy (compare `on` length) . words

mostFrequentChar :: String -> Char
mostFrequentChar = head . maximumBy (compare `on` length) . group . sort

myOr :: [Bool] -> Bool
myOr = foldl (||) False

isort :: Ord a => [a] -> [a]
-- isort []     = []
-- isort (x:xs) = isort_h x (isort xs)
isort = foldr isort_h [] 
    where
        isort_h e [] = [e]
        isort_h e (x:xs)
         | e < x     = e : x : xs
         | otherwise = x : isort_h e xs

myUnzip :: [(a,b)] -> ([a], [b])
myUnzip = foldr unzip_h ([], [])
 where
  unzip_h (a, b) (xs, ys) = (a:xs, b:ys)

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition f = foldr (part_h f) ([], [])
 where
  part_h f x (as, bs)
   | f x       = (x : as, bs)
   | otherwise = (as, x : bs)

compressPairs :: Eq a => [(a,b)] -> [(a,[b])]
compressPairs = foldr pair_h []
 where
  pair_h (a, b) [] = [(a, [b])]
  pair_h (a, b) ls@((x, ys):xs)
   | a == x    = (x, b : ys) : xs
   | otherwise = (a, [b]) : ls

maxIndex :: Ord a => [a] -> Int
maxIndex = fst . foldr1 maxind_h . zip [1..]
 where
  maxind_h v@(i, x) w@(j, y)
   | x > y     = v
   | otherwise = w

maxIndices :: Ord a => [a] -> [Int]
maxIndices = map fst . sortBy (compare `on` snd) . zip [1..]

maxDivisorsUntil :: Integer -> Integer
maxDivisorsUntil n = maximumBy (compare `on` length . divisors) [1..n]
