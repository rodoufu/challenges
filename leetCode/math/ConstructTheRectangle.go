// https://leetcode.com/problems/construct-the-rectangle/
func constructRectangle(area int) []int {
    length := int(math.Sqrt(float64(area)))
    width := area / length
    for ; length > 1; {
        if length * width == area {
            if length >= width {
                return []int{length, width}
            }
            return []int{width, length}
        }
        length--
        width = area / length
    }
    
    return []int{area, 1}
}
