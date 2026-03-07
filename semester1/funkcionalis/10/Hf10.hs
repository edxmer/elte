module Hf10 where

import Data.Char (isDigit, digitToInt)

data Triple a b c = T a b c deriving (Eq, Show)


readInt :: [Char] -> Maybe Int
readInt str = readInt' str (Just 0)
    where 
        addMaybe :: Maybe Int -> Maybe Int -> Maybe Int
        addMaybe _        Nothing  = Nothing
        addMaybe Nothing  _        = Nothing
        addMaybe (Just x) (Just y) = Just (x+y)
        
        multMaybe :: Maybe Int -> Maybe Int -> Maybe Int
        multMaybe _        Nothing  = Nothing
        multMaybe Nothing  _        = Nothing
        multMaybe (Just x) (Just y) = Just (x*y)
        
        readInt' :: [Char] -> Maybe Int -> Maybe Int
        readInt' [] acc = acc
        readInt' (x:xs) acc
            | isDigit x = readInt' xs ( addMaybe (Just (digitToInt x)) ( multMaybe (acc) (Just 10) ) )
            | otherwise = Nothing
