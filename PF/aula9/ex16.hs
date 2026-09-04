{- Repetidamente lê uma sequência de números (um por linha) até 
   encontrar o valor zero, e mostra a soma dos números lidos.
-}

-- solução com recursividade de cauda

module Main (main) where

main = do putStrLn "Digite uma sequência de números (um por linha)"
          putStrLn "Para terminar digite o valor zero"
          soma <- lerESomar 0
          putStr "A soma dos números digitados é "
          putStrLn (show soma)

lerESomar total = do n <- readLn
                     if n == 0
                     then return total
                     else lerESomar (total + n)

