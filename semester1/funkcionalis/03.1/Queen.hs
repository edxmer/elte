module Queen where

--  A megoldásokért:
--  queens 8


{-

7 - - - O - - - -
6 - - - - - - - -
5 - - - - - - - -
4 - - O - - - - -
3 - - - - - O - -
2 - O - - - - - -
1 - - - - O - - -
0 O - - - - - - -
  0 1 2 3 4 5 6 7

7 - - - - - - - O
6 - - - - - - - -
5 - - - - - - O -
4 - - - - - - - -
3 - - - - - O - -
2 - - - - - - - -
1 - - - - - - - -
0 - - - - O - - -
  0 1 2 3 4 5 6 7

-}


-- q: az éppen tesztelt queen pozíció, b: queenek pozíciójának sorszáma
-- True, ha jó a hely
-- False, ha nem jó a hely
sorban :: Int -> [Int] -> Bool
sorban q b = not ( q `elem` b )


-- q:       az éppen tesztelt queen pozíció
-- b:       queenek pozíciójának sorszáma, i: ahol éppen járok a vizsgálatban
-- hossz:   length (list) fv.
-- úgy nézem, mintha balra próbálnám tenni az új királynőt
-- True, ha jó a hely
-- False, ha nem jó a hely 
oszlopban :: Int -> [Int] -> Bool
oszlopban q b = oszlopban_recursive q b (length b - 1)
oszlopban_recursive :: Int -> [Int] -> Int -> Bool
-- A vizsgálat jobbról balra fog menni. Az indexelés 0-tól keződik, tehát a jobb index = n-1
oszlopban_recursive q b 0 = not ( ( (q + 1) == (b !! 0) ) || ( (q - 1) == (b !! 0) ) )
oszlopban_recursive q b i = not ( ( (q + i + 1) == (b !! i) ) || ( (q - i - 1) == (b !! i) ) ) && oszlopban_recursive q b (i-1)



jo_hely :: Int -> [Int] -> Bool
jo_hely q b = oszlopban q b && sorban q b

-- return is a list of possible queens to put on the left for the input position b
possible_queens :: [Int] -> [Int]
possible_queens b = filter (`jo_hely` b) [0..7]



add_spots :: [Int] -> [Int] -> Int -> [[Int]]
add_spots s b (-1) = []
add_spots s b i = add_spots s b (i-1) ++ [(s !! i):b]



tryspot :: [Int] -> [[Int]]
tryspot b = add_spots (possible_queens b) b (length (possible_queens b) - 1)




tryspots_recursive :: [[Int]] -> Int -> [[Int]]
tryspots_recursive c (-1) = []
tryspots_recursive c i = tryspots_recursive c (i-1) ++ tryspot (c !! i)


-- c:       list of possible queen positions, with length: length (c !! 0)
-- return:  list of possible queen positions, with length: length (c !! 0) + 1
tryspots :: [[Int]] -> [[Int]]
tryspots c = tryspots_recursive c (length c - 1)



-- i: number of columns, return: list of possible queen positions
queens :: Int -> [[Int]]
queens 1 = [[0], [1], [2], [3], [4], [5], [6], [7]]
queens i = tryspots (queens (i-1))