// https://leetcode.com/problems/game-of-life/
func gameOfLife(board [][]int)  {
    lenX := len(board)
    if lenX == 0 {
        return
    }
    lenY := len(board[0])
    if lenY == 0 {
        return
    }
    auxBoard := make([][]int, lenX)
    for i := 0; i < lenX; i++ {
        auxBoard[i] = make([]int, lenY)
    }

    for i := 0; i < lenX; i++ {
        for j := 0; j < lenY; j++ {
            auxBoard[i][j] = board[i][j]
        }
    }

    for i := 0; i < lenX; i++ {
        for j := 0; j < lenY; j++ {
            live := 0
            dead := 0
            for ki := -1; ki <= 1; ki++ {
                for kj := -1; kj <= 1; kj ++ {
                    if ki == 0 && kj == 0 {
                        continue
                    }
                    if i + ki >= 0 && j + kj >= 0 && i + ki < lenX && j + kj < lenY {
                        if auxBoard[i + ki][j + kj] == 1 {
                            live++
                        } else {
                            dead++
                        }
                    }
                }
            }

            if board[i][j] == 1 {
                // live
                if live < 2 {
                    board[i][j] = 0
                } else if live == 2 || live == 3 {
                    board[i][j] = 1
                } else {
                    board[i][j] = 0
                }
            } else {
                // dead
                if live == 3 {
                    board[i][j] = 1
                }
            }
        }
    }
}
