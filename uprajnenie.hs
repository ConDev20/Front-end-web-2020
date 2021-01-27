main :: IO()
main = do
    print (isAscending(reverse (drop 1 (getLevel2 t2))))
-- take k
-- drop k
--zip' :: [a] -> [b] -> [(a, b)]
--zip' :: [a] -> [b] -> [(a, b)]
-- upr 12 mn dobro
data BTree = Empty | Node Int BTree BTree deriving Show

t2 :: BTree                                                                     --       5
t2 = Node 5 (Node 3 (Node 1 Empty Empty) (Node 3 Empty Empty))                  --      / \
            (Node 4 (Node 5 Empty Empty)                                        --     3   4
                    (Node 7 Empty Empty))                                       --    / \ / \
                                                                                --   1  3 5  7
height :: BTree -> Int
height Empty = 0
height (Node _ lt rt) = 1 + max (height lt) (height rt)

getLevel :: Int -> BTree -> [Int]
getLevel _ Empty          = []
getLevel 0 (Node v _ _)   = [v]
getLevel k (Node _ lt rt) = getLevel (k - 1) lt ++ getLevel (k - 1) rt

getLevel2 :: BTree -> [[Int]]
getLevel2 Empty = [[]]
getLevel2 a@(Node x lt rt) = helper (height a)
    where 
        helper height
            |height < 0 = []
            |otherwise = getLevel height a : helper (height - 1)

isAscending :: [[Int]] -> Bool
isAscending []         = True
isAscending [_]        = True
isAscending (x1:x2:xs) = sum x1 < sum x2 && isAscending (x2:xs)

divisors :: Integer -> [Integer]
divisors n = [d | d <- [1..(n-1)], mod n d == 0]

isPrime :: Integer -> Bool 
isPrime n = [1, n] == [d | d <- [1..n], mod n d == 0]

primesInRange :: Integer -> Integer -> [Integer]
primesInRange a b = [n | n <- [a..b], isPrime n]