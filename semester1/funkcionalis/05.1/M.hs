module M where


head :: [a] -> [a]
head [] = []
head (x:xs) = [x]


tail :: [a] -> [a]
tail [] = []    -- sokan nem szeretik az ilyen függvényeket, hiszen lehet hogy
                -- lesz olyan is amikor egy halmaz tail-jét szeretnénk, de
                -- valami hiba van, és akkor nem fog hibát adni amikor kéne neki
tail (x:xs) = xs

