// https://leetcode.com/problems/two-out-of-three/
func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) []int {
    numIds := map[int]map[int]struct{}{}
    for _, x := range nums1 {
        if _, ok := numIds[x]; !ok {
            numIds[x] = map[int]struct{}{}
        }
        numIds[x][1] = struct{}{}
    }
    for _, x := range nums2 {
        if _, ok := numIds[x]; !ok {
            numIds[x] = map[int]struct{}{}
        }
        numIds[x][2] = struct{}{}
    }
    for _, x := range nums3 {
        if _, ok := numIds[x]; !ok {
            numIds[x] = map[int]struct{}{}
        }
        numIds[x][3] = struct{}{}
    }
    var resp []int

    for x, nums := range numIds {
        if len(nums) > 1 {
            resp = append(resp, x)
        }
    }

    return resp
}
