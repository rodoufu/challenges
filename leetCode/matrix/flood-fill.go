// https://leetcode.com/problems/flood-fill/
type Pos struct {
    R int
    C int
}
func floodFillOldColor(image [][]int, sr int, sc int, newColor int, oldColor int) {
    //fmt.Printf("sr: %v, sc: %v, newColor: %v, oldColor: %v")
    if len(image) == 0 {
        return
    }
    lenR := len(image)
    lenC := len(image[0])
    var toCall []Pos
    if sr > 0 {
        /*if sc > 0 && image[sr - 1][sc - 1] == oldColor {
            toCall = append(toCall, Pos {R: sr - 1, C: sc - 1})
        }*/
        if image[sr - 1][sc] == oldColor {
            toCall = append(toCall, Pos {R: sr - 1, C: sc})
        }
        /*if sc + 1 < lenC && image[sr - 1][sc + 1] == oldColor {
            toCall = append(toCall, Pos {R: sr - 1, C: sc + 1})
        }*/
    }
    if sc > 0 && image[sr][sc - 1] == oldColor {
        toCall = append(toCall, Pos {R: sr, C: sc - 1})
    }
    if sc + 1 < lenC && image[sr][sc + 1] == oldColor {
        toCall = append(toCall, Pos {R: sr, C: sc + 1})
    }
    if sr + 1 < lenR {
        /*if sc > 0 && image[sr + 1][sc - 1] == oldColor {
            toCall = append(toCall, Pos {R: sr + 1, C: sc - 1})
        }*/
        if image[sr + 1][sc] == oldColor {
            toCall = append(toCall, Pos {R: sr + 1, C: sc})
        }
        /*if sc + 1 < lenC && image[sr + 1][sc + 1] == oldColor {
            toCall = append(toCall, Pos {R: sr + 1, C: sc + 1})
        }*/
    }
    image[sr][sc] = -newColor
    for _, pos := range toCall {
        floodFillOldColor(image, pos.R, pos.C, newColor, oldColor)
    }
}

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
    floodFillOldColor(image, sr, sc, newColor, image[sr][sc])
    lenR := len(image)
    if lenR == 0 {
        return image
    }
    lenC := len(image[0])
    for i := 0; i < lenR; i++ {
        for j := 0; j < lenC; j++ {
            if image[i][j] < 0 {
                image[i][j] *= -1
            }
        }
    }
    return image
}
