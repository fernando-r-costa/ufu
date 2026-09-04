{- Repetidamente lê uma sequência de números (um por linha) até 
   encontrar o valor zero, e mostra a soma dos números lidos.
-}

-- solução que separa a leitura do processamento
-- sem recursividade de cauda

module Main (main) where

main = do putStrLn "Digite uma sequência de números (um por linha)"
          putStrLn "Para terminar digite o valor zero"
          lista <- lerLista 
          putStr "A soma dos números digitados é "
          putStrLn (show (sum lista))

lerLista = do x <- readLn
              if x == 0
              then return []
              else do resto <- lerLista
                      return (x:resto)

