permutations :: Eq a => [a] -> [[a]]
permutations [] = []
permutations [x] = [[x]]
permutations xs = [x : ys | x <- xs, ys <- permutations $ filter (/= x) xs]

param :: [[Integer]]
param =
  [ [1, 2, 3],
    [0, 1],
    [1],
    [5, 4, 6, 2]
  ]

printRecord :: [[Integer]] -> IO ()
printRecord [] = pure ()
printRecord [x] = print $ show x ++ "\n"
printRecord (x:xs) = do
  print $ show x ++ "\n"
  printRecord xs

main :: IO ()
main = do
  sequence_ $ [printRecord $ permutations xs | xs <- param]
