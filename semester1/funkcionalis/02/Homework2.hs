module Homework2 where

xor :: Bool -> Bool -> Bool
xor x y = not x == y



infix 1 -->
(-->) :: Bool -> Bool -> Bool
True --> x = x
_ --> _ = True



xor3 :: Bool -> Bool -> Bool -> Bool
xor3 True True x = x
xor3 x False False = x
xor3 False x False = x
xor3 False False x = x
xor3 _ _ _ = False