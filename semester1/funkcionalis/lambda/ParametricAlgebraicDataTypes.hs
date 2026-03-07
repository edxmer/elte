module ParametricAlgebraicDataTypes where


import Data.Char (isDigit, digitToInt)


-- data Maybe a = Nothing | Just a


maybeAdd :: Num a => Maybe a -> Maybe a -> Maybe a
maybeAdd (Just a) (Just b) = Just (a + b)
maybeAdd x Nothing = x
maybeAdd _ x = x


{-

maybeAdd (Just a) (Just b) = Just (a + b)
maybeAdd i@(Just x) Nothing = i
maybeAdd _ x = x

x:i@(y:xs)

Összefoglaló jel

-}


elemIndex :: Eq a => a -> [a] -> Maybe Int
elemIndex _ [] = Nothing
elemIndex a (x:xs)
 | a == x    = Just 0
 | otherwise = nAdd (Just 1) (elemIndex a xs)
  where
   nAdd (Just a) (Just b) = Just (a + b)
   nAdd _        _        = Nothing
 -- Ezt meg lehetne Zip-pel is oldani
 

maybeSum :: Num a => [Maybe a] -> a
maybeSum ls = fromMaybe (maybeSumH ls)
 where
  fromMaybe (Just x) = x
  fromMaybe Nothing = 0
  maybeSumH []     = Just 0
  maybeSumH (x:xs) = maybeAdd x (maybeSumH xs)



data Pair a b = P a b deriving (Eq)


instance (Show a, Show b) => Show (Pair a b) where
    show (P x y) = "(" ++ show x ++ ", " ++ show y ++ ")"


data List a = Nil | Cons a (List a) deriving (Eq)
infixr 5 `Cons`



consLength :: (List a) -> Int
consLength Nil = 0
consLength (Cons _ xs) = 1 + consLength xs


consReverse :: List a -> List a
consReverse ls = consReverseH ls Nil
    where
        consReverseH :: List a -> List a -> List a
        consReverseH Nil         acc = acc
        consReverseH (Cons x xs) acc = consReverseH xs (Cons x acc)


{-readInt str
 | v == -1   = Nothing
 | otherwise = Just v
 where 
  v = help str 0
  help :: [Char] -> Int -> Int
  help [] acc = acc
  help (x:xs) acc
   | isDigit x = help xs (acc*10 + digitToInt x)
   | otherwise = -1 -}

readInt str = help str 0
 where
  help :: [Char] -> Int -> Maybe Int
  help [] acc = Just acc
  help (x:xs) acc
   | isDigit x = help xs (acc*10 + digitToInt x)
   | otherwise = Nothing


list2ConsList :: [a] -> List a
list2ConsList [] = Nil
list2ConsList (x:xs) = x `Cons` list2ConsList xs


consProduct :: Num a => List a -> a
consProduct Nil           = 1
consProduct (x `Cons` xs) = x * consProduct xs 



consElem :: (Eq a) => a -> List a -> Bool
consElem _ Nil = False
consElem e (x `Cons` xs)
    | e == x    = True
    | otherwise = consElem e xs

instance (Show a) => Show (List a) where
    show ls = "<" ++ help ls
        where
            help :: Show a => List a -> [Char]
            help Nil            = ">"
            help (x `Cons` Nil) = show x ++ ">"
            help (x `Cons` xs)  = (show x) ++ ";" ++ (help xs)



data Triple a b c = T a b c
instance (Eq a, Eq b, Eq c) => Eq (Triple a b c) where
    (==) (T x y z) (T u v w) = (x == u) && (y == v) &&(z == w)

instance (Show a, Show b, Show c) => Show (Triple a b c) where
    show (T x y z) = "/" ++ (show x) ++ "/" ++ (show y) ++ "/" ++ (show z) ++ "/"

instance (Ord a, Ord b, Ord c) => Ord (Triple a b c) where
    (<=) (T x y z) (T u v w) = (x <= u) && (y <= v) && (z <= w)


data BinTree a = Leaf | Node a (BinTree a) (BinTree a) deriving (Show)


incNodes :: Num a => BinTree a -> BinTree a
incNodes Leaf = Leaf
incNodes (Node x xs ys) = Node (x+1) (incNodes xs) (incNodes ys)


sumNodes :: Num a => BinTree a -> a
sumNodes Leaf = 0
sumNodes (Node x xs ys) = x + (sumNodes xs) + (sumNodes ys)


instance (Eq a) => Eq (BinTree a) where
    (==) Leaf Leaf  = True
    (==) (Node x xs ys) (Node v vs ws)
        | x == v    = (xs == vs) && (ys == ws)
    (==) _    _     = False
