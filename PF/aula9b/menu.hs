-- |

module Main (main) where

import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))

fatorial :: Integer -> Integer
fatorial n | n < 0 = error "O número deve ser positivo ou zero"
           | otherwise = product [1..n]


fibonacci :: Integer -> Integer
fibonacci n | n < 1 = error "O número deve ser estritamente positivo"
            | n <= 2 = n - 1
            | otherwise = fib 3 0 1
            where
              fib i f1 f2 = if i > n then f2
                            else fib (i+1) f2 (f1+f2)


prompt :: Read a => String -> IO a
prompt msg = do putStr msg
                readLn


exibirOpções :: [String] -> IO ()
exibirOpções opções = do
  putStrLn ""
  putStrLn "Opções:"
  putStrLn ""
  putStrLn (unlines opções)
  putStrLn ""


lerOpção :: Int -> Int -> IO Int
lerOpção mínima máxima = do putStr "Digite uma opção: "
                            opção <- readLn
                            valida opção
  where
    valida opção | mínima <= opção && opção <= máxima = return opção
                 | otherwise = do putStrLn "Opção inválida!"
                                  putStrLn ""
                                  putStr "Digite uma opção: "
                                  opção <- readLn
                                  valida opção


imprimirResultado :: Int -> Integer -> Integer -> IO ()
imprimirResultado opção n res = do
     putStrLn ""
     putStrLn "--------------------------------------------------"
     case opção of
        1 -> putStrLn strFat
        2 -> putStrLn strFib
        3 -> putStrLn strNovo
        _ -> putStrLn "Fim"
     putStrLn "--------------------------------------------------"
  where
     strFat = concat ["Fatorial de ", show n, " = ", show res]
     strFib = concat [show n, "-ésimo número de Fibonacci = ", show res]
     strNovo = "Novo natural lido = " ++ show n


menu :: IO Int
menu = do exibirOpções texto
          lerOpção opMín opMáx
  where
    texto = [ "1 - fatorial",
              "2 - n-ésimo número de Fibonacci",
              "3 - ler um novo natural",
              "0 - sair" ]
    opMín = 0
    opMáx = 3


laçoMenu :: Integer -> IO ()
laçoMenu n = do
  opção <- menu
  case opção of
     1 -> do imprimirResultado opção n (fatorial n)
             laçoMenu n
     2 -> do imprimirResultado opção n (fibonacci n)
             laçoMenu n
     3 -> do n <- prompt "Digite um natural: "
             laçoMenu n
     0 -> do imprimirResultado opção n 0
             return ()


main :: IO ()
main = do hSetBuffering stdout NoBuffering
          n <- prompt "Digite um natural: "
          laçoMenu n
