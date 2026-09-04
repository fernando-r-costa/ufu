min :: Int -> Int -> Int
min a b
  | a < b = a
  | otherwise = b

minTres :: Int -> Int -> Int -> Int
minTres a b c
  | a < b && a < c = a
  | b < c = b
  | otherwise = c