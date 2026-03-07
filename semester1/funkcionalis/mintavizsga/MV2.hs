module MV2 where

points :: Integral a => [(String, a, a)] -> [(String, a)]
points = filter (\(name, p) -> p > 0) . map (\(name, t, m) -> (name, 100 - (t `div` 2) - m) )


-- ne feledjük bemásolni a modulba
type Apple = (Bool, Int)
type Tree = [Apple]
type Garden = [Tree]

-- [(,)]
ryuksApples :: Garden -> Int
ryuksApples = length . filter (\(ripeness, h) -> ripeness && h <= 3) . concat


doesContain :: String -> String -> Bool
doesContain [] _ = True
doesContain _ [] = False
doesContain str@(x:xs) (y:ys)
    | x == y    = doesContain xs  ys
    | otherwise = doesContain str ys


barbie :: [String] -> String
barbie = barbie_h 1
    where
        barbie_h i (x:xs)
            | x == "rozsaszin"                  = x
            | i `mod` 2 == 0 && x /= "fekete"   = x
            | otherwise                         = barbie_h (i+1) xs
        barbie_h _ _ = "farmer"


firstValid :: [a -> Bool] -> a -> Maybe Int
firstValid = fv_h 0
    where
        fv_h :: Int -> [a -> Bool] -> a -> Maybe Int
        fv_h i (f:fs) e
            | f e       = Just i
            | otherwise = fv_h (i+1) fs e
        fv_h _ _ _ = Nothing


combineListsIf :: (a -> b -> Bool) -> (a -> b -> c) -> [a] -> [b] -> [c]
combineListsIf t f (x:xs) (y:ys)
    | t x y     = f x y : combineListsIf t f xs ys
    | otherwise = combineListsIf t f xs ys
combineListsIf _ _ _ _ = []


data Line = Tram Integer [String] | Bus Integer [String] deriving (Eq, Show)

whichBusStop :: String -> [Line] -> [Integer]
whichBusStop str ((Bus i ls):xs)
    | str `elem` ls = i : whichBusStop str xs
    | otherwise     = whichBusStop str xs
whichBusStop str ((Tram _ _):xs) = whichBusStop str xs
whichBusStop _ _ = []



isReservable :: Int -> String -> Bool
isReservable = isr_h 0
    where
        isr_h :: Int -> Int -> String -> Bool
        isr_h i n (x:xs)
            | i == n    = True
            | x == 'x'  = isr_h (i+1) n xs
            | otherwise = isr_h 0 n xs
        isr_h i n _ | i == n = True
        isr_h _ _ _ = False
