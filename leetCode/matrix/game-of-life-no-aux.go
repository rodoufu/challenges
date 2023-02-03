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

    //isUpdated := map[int]struct{}{}
    var toUpdate []int
    /*isLive := func(x, y int) bool {
        val := board[x][y]
        if _, ok := isUpdated[x * lenY + y]; ok {
            return val != 1
        }
        return val == 1
    }*/
    addToUpdate := func(x, y int) {
        //fmt.Printf("toUpdate[%v, %v] or %v\n", x, y, x * lenY + y)
        //toUpdate = append(toUpdate, []int{x, y})
        toUpdate = append(toUpdate, x * lenY + y)
        
        //isUpdated[x * lenY + y] = struct{}{}
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
                        //if isLive(i + ki, j + kj) {
                        if board[i + ki][j + kj] == 1 {
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
                    addToUpdate(i, j)
                    //board[i][j] = 0
                } else if live == 2 || live == 3 {
                    // board[i][j] = 1
                } else {
                    addToUpdate(i, j)
                    //board[i][j] = 0
                }
            } else {
                // dead
                if live == 3 {
                    addToUpdate(i, j)
                    //board[i][j] = 1
                }
            }
        }

        var updated int
        fixToUpdate := false
        for updated = 0; updated < len(toUpdate); updated++ {
            aux := toUpdate[updated]
            if aux / lenY == i - 2 {
                board[aux / lenY][aux % lenY] = (board[aux / lenY][aux % lenY] + 1) % 2
                //delete(isUpdated, aux[0] * lenY + aux[1])
                fixToUpdate = true
            } else {
                break
            }
        }
        if fixToUpdate {
            toUpdate = toUpdate[updated:]
        }
    }

    for _, idx := range toUpdate {
        board[idx / lenY][idx % lenY] = (board[idx / lenY][idx % lenY] + 1) % 2
    }
}
