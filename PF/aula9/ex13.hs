-- module Main (main) where
import System.IO (stdout, hSetBuffering, BufferMode(NoBuffering))

-- Raízes da equação do segundo grau

raízes2grau a b c
  | d > 0  = [ (-b + sqrt d)/(2*a), (-b - sqrt d)/(2*a) ]
  | d == 0 = [ -b/(2*a) ]
  | otherwise = [ ]
  where d = b^2 - 4*a*c
   
prompt mensagem = do { putStr mensagem; readLn }

main = do hSetBuffering stdout NoBuffering
          putStrLn "Cálculo das raízes da equação do segundo grau"
          putStrLn "a x^2 + b x + c = 0"
          a <- prompt "Coeficiente a: "
          b <- prompt "Coeficiente b: "
          c <- prompt "Coeficiente c: "
          case raízes2grau a b c of
            [r1,r2] -> putStrLn ("Raízes: " ++ show r1 ++ " e " ++ show r2)
            [r]     -> putStrLn ("Raíz: " ++ show r)
            []      -> putStrLn "Não há raízes reais"
