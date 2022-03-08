// https://leetcode.com/problems/largest-triangle-area/
func largestTriangleArea(points [][]int) float64 {
    lenP := len(points)
    var largest float64 = 0.0
    for a := 0; a < lenP; a++ {
        for b := a + 1; b < lenP; b++ {
            for c := b + 1; c < lenP; c++ {
                area := float64(points[a][0] * points[b][1])
                area += float64(points[c][0] * points[a][1])
                area += float64(points[b][0] * points[c][1])
                
                area -= float64(points[c][0] * points[b][1])
                area -= float64(points[a][0] * points[c][1])
                area -= float64(points[b][0] * points[a][1])
                if area < 0 {
                    area *= -1
                }
                if area > largest {
                    largest = area
                }
            }
        }
    }
    return largest / 2.0
}
