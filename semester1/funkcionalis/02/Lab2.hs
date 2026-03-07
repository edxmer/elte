module Lab2 where

multAdd :: Int -> Int -> Int
multAdd n m = n * m + n + m

-- Mintaillesztés:
myNot0 :: Bool -> Bool
myNot0 True = False
myNot0 False = True

myNot1 :: Bool -> Bool
myNot1 True = False
myNot1 n = True

myNot :: Bool -> Bool
myNot True = False
myNot _ = True -- _ -t szokás használni az olyan változóknál, amit nem szeretnénék használni később, de bármilyen másik változónevet is lehetne használni


myAnd0 :: Bool -> Bool -> Bool
myAnd0 True True = True
myAnd0 True False = False
myAnd0 False True = False
myAnd0 False False = False


myAnd1 :: Bool -> Bool -> Bool
myAnd1 True True = True
myAnd1 x y = False

myAnd2 :: Bool -> Bool -> Bool
myAnd2 True True = True
myAnd2 _ _ = False


-- A lusta kiértékelés miatt ez a leggyorsabb
myAnd :: Bool -> Bool -> Bool
myAnd True x = x
myAnd _ _ = False


-----

infixr 2 |:|

(|:|) :: Bool -> Bool -> Bool
(|:|) False x = x
(|:|) _ _ = True

-- Lehet egyből infix-esen is definiálni

infixr 2 |?|

(|?|) :: Bool -> Bool -> Bool
False |?| x = x
_ |?| _ = True



-----