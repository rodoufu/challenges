// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
func absInt(x int) int {
    if x < 0 {
        return - x
    }
    return x
}
func findTheDistanceValue(arr1 []int, arr2 []int, d int) int {
    //sort.Ints(arr1)
    //sort.Ints(arr2)
    
    dist := 0
    for _, x := range arr1 {
        v := true
        for _, y := range arr2 {
            if absInt(x - y) <= d {
                v = false
                break
            }
        }
        if v {
            dist++
        }
    }
    
    return dist
}
