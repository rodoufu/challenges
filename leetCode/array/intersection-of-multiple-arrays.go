// https://leetcode.com/problems/intersection-of-multiple-arrays/
func intersection(nums [][]int) []int {
    intersecitionElemens := map[int]struct{}{}
    
    for idx, elemens := range nums {
        if idx == 0 {
            for _, x := range elemens {
                intersecitionElemens[x] = struct{}{}
            }
            continue
        }
        
        
        newIntersec := map[int]struct{}{}
        for _, x := range elemens {
            if _, ok := intersecitionElemens[x]; ok {
                newIntersec[x] = struct{}{}
            }
        }
        intersecitionElemens = newIntersec
        if len(intersecitionElemens) == 0 {
            break
        }
    }
    
    var resp []int
    for x, _ := range intersecitionElemens {
        resp = append(resp, x)
    }
    sort.Ints(resp)
    return resp 
}
