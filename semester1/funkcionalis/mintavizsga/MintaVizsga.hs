module MintaVizsga where

points :: Integral a => [(String, a, a)] -> [(String, a)]
points = filter (\(name, p) -> p > 0) . map (\(name, t, m) -> (name, 100 - (t `div` 2) - m))


-- ne feledjük bemásolni a modulba
type Apple = (Bool, Int)
type Tree = [Apple]
type Garden = [Tree]

ryuksApples :: Garden -> Int
ryuksApples = length . filter (\(r, h) -> r && (h <= 3)) . concat


doesContain :: String -> String -> Bool
doesContain []      _   = True
doesContain _      []   = False
doesContain (x:xs) (y:ys)
    | x == y            = doesContain xs ys
    | otherwise         = doesContain (x:xs) ys


barbie :: [String] -> String
barbie ls = barbie_h ls 1
    where
        barbie_h [] _   = "farmer"
        barbie_h (x:xs) i
            | ((i `mod` 2 == 0) && (x /= "fekete")) || x == "rozsaszin"     = x
            | otherwise                                                     = barbie_h xs (i+1)


firstValid :: [a -> Bool] -> a -> Maybe Int
firstValid fs       e   = firstValid_h fs e 0
    where
        firstValid_h []     _   _ = Nothing
        firstValid_h (f:fs) e   i
            |   f e         = Just i
            |   otherwise   = firstValid_h fs e (i+1)



combineListsIf :: (a -> b -> Bool) -> (a -> b -> c) -> [a] -> [b] -> [c]
combineListsIf  t   f   (x:xs)  (y:ys)
    | t x y                         = f x y : combineListsIf t f xs ys
    | otherwise                     = combineListsIf t f xs ys
combineListsIf  _   _   _       _   = []



data Line = Tram Integer [String] | Bus Integer [String] deriving (Eq, Show)


whichBusStop :: String -> [Line] -> [Integer]
whichBusStop    _   []          = []
whichBusStop    str ((Bus id stops):xs)
    | str `elem` stops  = id : whichBusStop str xs
    | otherwise         = whichBusStop str xs
whichBusStop    str ((Tram _ _):xs) = whichBusStop str xs


isReservable :: Int -> String -> Bool
isReservable = res_h 0
    where
        res_h :: Int -> Int -> String -> Bool
        res_h i n (x:xs)
            | i == n    = True
            | x == 'o'  = res_h 0       n   xs
            | otherwise = res_h (i+1)   n   xs
        res_h i n _
            | i == n    = True
            | otherwise = False
