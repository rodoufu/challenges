// https://leetcode.com/problems/find-greatest-common-divisor-of-array/
func gdc(a, b int) int {
    for b != 0 {
        t := b
        b = a % b
        a = t
    }
    return a
}

func findGCD(nums []int) int {
    smallest := nums[0]
    largest := nums[0]
    for _, x := range nums {
        if x < smallest {
            smallest = x
        }
        if x > largest {
            largest = x
        }
    }
    return gdc(smallest, largest)
}
