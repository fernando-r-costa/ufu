--1
minDois :: Int -> Int -> Int
minDois a b
  | a < b = a
  | otherwise = b

minTres :: Int -> Int -> Int -> Int
minTres a b c
  | a < b && a < c = a
  | b < c = b
  | otherwise = c

--2
converteLetra :: Char -> Char
converteLetra c
  | c >= 'a' && c <= 'z' = toEnum (fromEnum c - 32)
  | otherwise            = c

maiusculas :: String -> String
maiusculas "" = ""
maiusculas (cabeca:cauda) = converteLetra cabeca : maiusculas cauda

--3
char2Num :: Char -> Int
char2Num c
  | fromEnum c >= 48 && fromEnum c <= 57 = fromEnum c - 48
  | otherwise = 0

--4
digitoRomano :: Char -> String
digitoRomano c
  | c == '1' = "I"
  | c == '2' = "II"
  | c == '3' = "III"
  | c == '4' = "IV"
  | c == '5' = "V"
  | c == '6' = "VI"
  | c == '7' = "VII"
  | c == '8' = "VIII"
  | c == '9' = "IX"
  | otherwise = ""

--5
mediaTres :: Integer -> Integer -> Integer -> Double
mediaTres a b c = fromIntegral (a + b + c) / 3.0

quantosAcimaMedia :: Integer -> Integer -> Integer -> Integer
quantosAcimaMedia a b c = testa a + testa b + testa c
  where
    media = mediaTres a b c
    
    testa n
      | fromIntegral n > media = 1
      | otherwise              = 0  