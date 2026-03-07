module ListaTovabbiFeladatok where

import Data.Char (isUpper)


isLongerThan :: [a] -> Integer -> Bool
isLongerThan [] n 
 | n > 0 = False
 | n <= 0 = True
isLongerThan (_:_) n | n <= 0 = True
isLongerThan (x:xs) n = isLongerThan xs (n-1)


onlyUppers :: String -> String
onlyUppers [] = []
onlyUppers (x:xs)
 | isUpper x = x:onlyUppers xs
 | otherwise = onlyUppers xs


elemIds :: Eq a => a -> [a] -> [Int]
elemIds e l = elemIdsH e l 0
  where
    elemIdsH _ [] _ = []
    elemIdsH e (x:xs) i
      | e == x = i : elemIdsH e xs (i+1)
      | otherwise = elemIdsH e xs (i+1)


injectElem :: a -> [a] -> [a]
injectElem _ [] = []
injectElem _ [x] = [x]
injectElem e (x:xs) = x : e : injectElem e xs


ordInsert :: Ord a => a -> [a] -> [a]
ordInsert e [] = [e]
ordInsert e (x:xs)
 | e < x = e : x : xs
 | otherwise = x : ordInsert e xs


sortedMerge :: Ord a => [a] -> [a] -> [a]
sortedMerge [] [] = []
sortedMerge [] x = x
sortedMerge x [] = x
sortedMerge (x:xs) (y:ys)
 | x <= y = x : sortedMerge xs (y:ys)
 | otherwise = y : sortedMerge (x:xs) ys


suffixes :: [a] -> [[a]]
suffixes [] = [[]]
suffixes (x:xs) = (x:xs) : suffixes xs


slice :: [Int] -> [a] -> [[a]]
slice [] _ = []
slice (x:xs) l = (take x l) : slice xs (drop x l)


polinom :: Num a => [a] -> a -> a
polinom [] _ = 0
polinom (a:as) x = a + x * polinom as x


toBin :: Integer -> [Integer]
toBin 0 = []
toBin x
 | x `mod` 2 == 0 = 0 : toBin (x `div` 2)
 | otherwise      = 1 : toBin ( (x-1) `div` 2 )


fromBin :: [Integer] -> Integer
fromBin x = fromBinH x 1
    where
        fromBinH [] _ = 0
        fromBinH (x:xs) he = x*he + fromBinH xs (he*2)