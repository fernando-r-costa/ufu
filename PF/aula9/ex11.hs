-- module Main (main) where
import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))
import Data.Char (toUpper)

-- Cálculo do peso ideal

main :: IO ()
main = do hSetBuffering stdout NoBuffering
          putStr "Altura: "
          h <- readLn
          putStr "Sexo (f/m): "
          s <- getLine
          case toUpper (head s) of
            'F' -> putStrLn ("Peso ideal: " ++ show (62.1 * h - 44.7))
            'M' -> putStrLn ("Peso ideal: " ++ show (72.7 * h - 58))
            _  -> putStrLn "Sexo inválido"
