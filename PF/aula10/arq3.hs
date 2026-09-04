module Main (main) where

import Data.Char (toLower)

-- converte as letras de uma string para minúsculas,
-- deixando todo os demais caracteres inalterados
tudoMinusculo conteudo = resultado
  where
    linhas = lines conteudo
    minusculas l = map toLower l
    linhasMin = map minusculas linhas
    resultado = unlines linhasMin
    
    
-- Lê o arquivo dado, transforma todas as letras para minúsculas
-- e depois escreve o resultado para o arquivo "minusculas.txt"
main :: IO ()
main = do conteúdo <- readFile "entrada.txt"
          writeFile "minusculas.txt" (tudoMinusculo conteúdo)

