//https://leetcode.com/problems/determine-color-of-a-chessboard-square/
func squareIsWhite(coordinates string) bool {
    val := int(coordinates[0]) - int('a') + int(coordinates[1]) - int('0')
    return val % 2 == 0
}
