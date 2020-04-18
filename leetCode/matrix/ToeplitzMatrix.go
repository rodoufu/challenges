// https://leetcode.com/problems/toeplitz-matrix/
func isToeplitzMatrix(matrix [][]int) bool {
    leni := len(matrix)
    if leni < 2 {
        return true
    }
    lenj := len(matrix[0])
    if lenj < 2 {
        return true
    }
    
    for i := 0; i < leni; i++ {
        for j := 0; j < lenj; j++ {
            for k := 0; i + k < leni - 1 && j + k < lenj - 1; k++ {
                if matrix[i + k][j + k] != matrix[i + k + 1][j + k + 1] {
                    return false
                }
            }
        }
    }
    
    return true
}
