-- module Main (main) where

tabela :: String -> [[String]]
tabela conteúdo = campos
  where
     linhas = lines conteúdo
     novasLinhas = filter (/= []) linhas -- remove linhas em branco
     campos = map words novasLinhas


médias :: [[String]] -> [Double]
médias [] = []
médias ([_,_,s1,s2]:xs) = m : médias xs
  where 
    m = ((read s1) + (read s2)) / 2.0

situação ns = map sit ns
 where
     sit n | n < 3 = "reprovado"
           | n < 7 = "exame especial"
           | otherwise = "aprovado"


processa :: String -> String
processa conteúdo = unlines (novaTab tab meds sits)
  where
    tab = tabela conteúdo
    meds = médias tab
    sits = situação meds
    
    novaTab [] _ _ = []
    novaTab (l:ls) (m:ms) (situacao:sits) = linha: novaTab ls ms sits
      where
        linha = unwords (l ++ [show m, situacao])
     

main :: IO ()
main = do conteúdo <- readFile "entrada.txt"
          writeFile "saídaAula10b.txt" (processa conteúdo)

------------------------------
--        Observação        --
------------------------------
- Se quiser que a saída seja formatada inclua o módulo Text.Printf
- no topo deste arquivo usando:
- import Text.Printf
-
- Depois use a função printf.
- 
- A documentação sobre o uso desta função está em:
- https://hackage.haskell.org/package/base-4.20.0.1/docs/Text-Printf.html


------------------------------
--          Testes          --
------------------------------

conteúdoArq = "1234  Pedro    1.5   1.7\n1111  Carla    6.2   7.0"

-- Saída esperada de: 
--   tabela conteúdoArq
tab = [["1234","Pedro","1.5","1.7"],
       ["1111","Carla","6.2","7.0"]]
       
-- Saída esperada de:    
-- médias tab
meds = [1.6, 6.6]

-- Saída esperada de 
-- processa conteúdoArq
novasLinhas = "1234 Pedro 1.5 1.7 1.6 reprovado\n1111 Carla 6.2 7.0 6.6 exame especial\n"


