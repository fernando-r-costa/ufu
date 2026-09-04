module Main (main) where
import System.Environment (getArgs, getProgName)

main =
   do progName <- getProgName
      putStrLn "O nome do programa é:"
      putStrLn progName
      putStrLn ""
      args <- getArgs
      putStrLn "Os argumentos são: "
      mapM putStrLn args
