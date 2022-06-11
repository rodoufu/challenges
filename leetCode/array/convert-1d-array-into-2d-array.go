// https://leetcode.com/problems/convert-1d-array-into-2d-array/
func construct2DArray(original []int, m int, n int) [][]int {
    if n * m != len(original) {
        return nil
    }
    if m == 1 {
        return [][]int{original}
    }
    resp := make([][]int, m)
    for i := 0; i < m; i++ {
        resp[i] = make([]int, n)
    }
    
    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            resp[i][j] = original[i*n + j]
        }
    }
    return resp
}
