duplicaElementos :: [a] -> [a]
duplicaElementos [] = []
duplicaElementos (x : xs) = x : x : duplicaElementos xs

--[1, 2, 3]
--1 : 1 : duplica [2, 3]
--1 : 1 : 2 : 2 : duplica [3]
--1 : 1 : 2 : 2 : 3 : 3 : duplica []
--caso base
--1 : 1 : 2 : 2 : 3 : 3 : []
--1 : 1 : 2 : 2 : 3 : [3]
--1 : 1 : 2 : 2 : [3, 3]
--1 : 1 : 2 : [2, 3, 3]
--1 : 1 : [2, 2, 3, 3]
--1 : [1, 2, 2, 3, 3]
--[1, 1, 2, 2, 3, 3]

detectaAlternado :: Eq a => [a] -> Bool
detectaAlternado [] = True
detectaAlternado [_] = True
detectaAlternado (x : y : xs)
  | x == y = False
  | otherwise = detectaAlternado (y : xs)

--[1, 2, 3, 4]
--1 : 2 : [3,4]
--2 : 3 : [4]
--3 : 4
--4 : []
--[] -> True

--[1, 2, 2, 4]
--1 : 2 : [2,4]
--2 : 2 : [4]
--2 = 2 -> False

--[]
-- ->True

--[1]
-- ->True

contaOcorrencia :: Eq a => a -> [a] -> Int
contaOcorrencia a [] = 0
contaOcorrencia a (x : xs)
  |x == a = 1 + contaOcorrencia a xs
  |otherwise = contaOcorrencia a xs


--contaOcorrencia banana
--b : [anana]
--contaOcorrencia anana
--a : [nana]
--1 + contaOcorrencia nana
--n : [ana]
--1 + contaOcorrencia ana
--a : [na]
--1 + 1 + contaOcorrencia na
--n : [a]
--1 + 1 + contaOcorrencia a
--a : []
--1 + 1 + 1 + contaOcorrencia []
--[]
--1 + 1 + 1 + 0
--1 + 1 + 1
--1 + 2
--3

resto :: Int -> Int
resto a
  | a `mod` 2 == 0 = 0
  | otherwise = a `mod` (2 + 1) 

ehPrimo :: Int -> Bool
ehPrimo n
  | n <= 1    = error "n deve ser > 1"
  | otherwise = aux 2
  where
    aux :: Int -> Bool
    aux candidato
      | candidato > (n `div` 2) = True
      | n `mod` candidato == 0  = False
      | otherwise               = aux (candidato + 1)

-- resto 5/2 = 0 não
-- resto 5/2+1 = 0
-- resto 5/3 = 0 não
-- resto 5/3+1 = 0 
-- resto 5/4 = 0 não
-- resto 5/5 = 0 && a == a sim

associaIndices :: [a] -> [(Int, a)]
associaIndices lista = auxiliar 1 lista
  where
    auxiliar :: Int -> [a] -> [(Int, a)]
    auxiliar _ [] = []
    auxiliar contador (x : xs) = (contador, x) : auxiliar (contador + 1) xs

duplique :: [a] -> [a]
duplique [] = []
duplique (x : xs) = x : x : duplique xs

replique :: [a] -> Int -> [a]
replique [] _ = []
replique (x : xs) a = repetidor x a ++ replique xs a
  where
    repetidor :: a -> Int -> [a]
    repetidor x a
      | a == 0 = []
      | otherwise = x : repetidor x (a - 1)

comprime :: Eq a => [a] -> [a]
comprime [] = []
comprime [_] = []
comprime (x : y : xs)
  | x == y = y : comprime xs
  | otherwise = comprime xs
      