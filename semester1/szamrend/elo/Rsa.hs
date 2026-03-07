module Rsa where



key :: (Integer, Integer)
key = (7, 187)

msg1 = [83, 162, 83, 46, 36, 162, 83, 83, 175]
msg2 = [162, 64, 181, 46, 36, 46, 181, 64, 162, 83, 162, 180, 150, 162]

rsa :: Integer -> Integer
rsa n = n ^ fst key `mod` snd key

decode_char 1 = 'A'
decode_char 2 = 'E'
decode_char 3 = 'É'
decode_char 4 = 'G'
decode_char 5 = 'K'
decode_char 6 = 'R'
decode_char 7 = 'S'
decode_char 8 = 'T'
decode_char 9 = 'Z'
decode_char 10 = '?'
decode_char _ = '_'

decode :: [Integer] -> String
decode msg = [(decode_char . rsa) x | x <- msg]

