// https://leetcode.com/problems/minimum-index-sum-of-two-lists/
func findRestaurant(list1 []string, list2 []string) []string {
    restList1 := make(map[string]int)
    for i, x := range list1 {
        restList1[x] = i
    }
    restList2 := make(map[string]int)
    for i, x := range list2 {
        restList2[x] = i
    }
    
    restBoth := make(map[string]int)
    minv := len(list1) + len(list2)
    for k1, v1 := range restList1 {
        if v2, ok := restList2[k1]; ok {
            restBoth[k1] = v1 + v2
            if v1 + v2 < minv {
                minv = v1 + v2
            }
        }
    }
    
    var resp []string
    for k, v := range restBoth {
        if v == minv {
            resp = append(resp, k)
        }
    }
    
    return resp
}
