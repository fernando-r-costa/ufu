primeiro :: Double -> Double -> Double
primeiro a b = (-b)/a


segundo :: Double -> Double -> Double -> [Double]
segundo a b c
  | d < 0     = []
  | d == 0    = [ (-b) / (2*a) ]
  | otherwise = [ (-b + sqrt d) / (2*a), (-b - sqrt d) / (2*a) ]
  where 
    d = delta a b c

delta :: Double -> Double -> Double -> Double
delta a b c = (b^2) - (4*a*c)

mdc :: Int -> Int -> Int
mdc a b
  | b == 0  = a
  | otherwise = mdc b (a `mod` b)

mmc :: Int -> Int -> Int
mmc a b
  | a == 0  = 0
  | b == 0  = 0
  | otherwise = (a * b) `div` (mdc a b)

verificaData :: Int -> Int -> Int -> Bool
verificaData d m a
  | d < 1 || d > 31 = False
  | a < 0 = False
  | m < 1 || m > 12 = False
  | m == 2 && d > 28 = False
  | (m == 4 || m == 6 || m == 9 || m == 11) && d > 30 = False
  | otherwise = True