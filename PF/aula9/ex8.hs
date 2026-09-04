-- module Main (main) where

main :: IO ()
main = do putStr "Digite um número: "
          n1 <- readLn
          putStr "Digite outro número: "
          n2 <- readLn
          putStr "Soma dos números digitados: "
          putStrLn (show (n1 + n2))
