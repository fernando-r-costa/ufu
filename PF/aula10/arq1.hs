module Main (main) where

main :: IO ()
main = do conteúdo <- readFile "entrada.txt"
          putStrLn conteúdo

