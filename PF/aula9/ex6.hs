-- module Main (main) where

main :: IO ()
main = do putStrLn "Qual é o seu nome? "
          nome <- getLine
          putStr nome
          putStrLn ", seja bem vindo(a)!"
