// https://leetcode.com/problems/next-greater-element-i/
func nextGreaterElement(nums1 []int, nums2 []int) []int {
    resp := make([]int, len(nums1))
    len2 := len(nums2)
    for i, x := range nums1 {
        resp[i] = -1
        j := 0
        for ; j < len2; j++ {
            if nums2[j] == x {
                break
            }
        }
        for j++; j < len2; j++ {
            if nums2[j] > x {
                resp[i] = nums2[j]
                break
            }
        }
    }
    
    return resp
}
