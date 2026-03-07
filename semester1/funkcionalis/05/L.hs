module L where

{-
f (True:xs) = 'f'

g (1:2:_) = 'g'

h (x:False:xs) = 'h'

i ([]:xs) = 'i' --}

f (1:x:xs) = 'a'
f (x:2:xs) = 'b'
f (1:[])   = 'c'
f _        = 'd'


g (_:True:_:xs) = True
g _ = False