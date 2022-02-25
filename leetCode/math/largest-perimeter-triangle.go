// https://leetcode.com/problems/largest-perimeter-triangle/
func abs(a int) int {
    if a >= 0 {
        return a
    }
    return -a
}
func calculatePerimeter(a, b, c int) int {
    if abs(a - c) < b  && b < a + c {
        return a + b + c
    }
    if abs(a - b) < c  && c < a + b {
        return a + b + c
    }
    if abs(b - c) < a  && a < b + c {
        return a + b + c
    }
    return 0
}
func largestPerimeter(nums []int) int {
    lenP := len(nums)
    largest := 0
    sort.Ints(nums)
    for a := lenP - 3; a >= 0; a-- {
        for b := lenP - 2; b > a; b-- {
            for c := lenP - 1; c > b; c-- {
                perimeter := calculatePerimeter(nums[a], nums[b], nums[c])
                if perimeter > largest {
                    largest = perimeter
                    return largest
                }
            }
        }
    }
    return largest
}
