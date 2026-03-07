module Conversions where


-- fromIntegral -- Integral-ból más Num típusba


-- round -- Ez mindig a páros fele kerekít, így lehet Integral-lá konvertőlni
-- truncate -- ez leveszi a törtrészt
-- floor
-- ceiling



watering :: Integer -> Integer
watering n = ceiling (fromIntegral n * 0.25 / 1.8)


iSqrt :: Integer -> Integer
iSqrt n = round (sqrt (fromIntegral n))


-- Data.Char-ból kell importálni
-- ord: karakterből karakterkód
-- chr: karakterkódból karakter


-- fromEnum: enumerált értékből szám
-- toEnum :: (Típus) 
--  számból enumerált érték, de specifikálni kell a típust
--
