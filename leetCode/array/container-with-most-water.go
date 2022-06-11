// https://leetcode.com/problems/container-with-most-water/
func minInt(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func maxArea(height []int) int {
    water := 0
    lenH := len(height)
    
    for i, j := 0, lenH - 1; i < lenH && i < j; {
        h := minInt(height[i], height[j])
        w := h * (j - i)
        //fmt.Printf("i: %v, j: %v, h: %v, w: %v\n", i, j, h, w)
        if w > water {
            water = w
            //fmt.Printf("water: %v\n", water)
        }
        
        if height[i] < height[j] {
            i++
        } else {
            j--
        }
    }
    return water
}
