// https://leetcode.com/problems/count-binary-substrings/
func countBinarySubstrings(s string) int {
    zeros := 0
    ones := 0
    lenS := len(s)
    count := 0
    
    for i := 0; i < lenS - 1; i++ {
        zeros = 0
        ones = 0
        for j := i; j <= lenS; j ++ {
            if j == lenS {
                if zeros == ones {
                    count++
                }
                break
            }
            if zeros == 0 || ones == 0 {
                if s[j] == '0' {
                    zeros++
                } else {
                    ones++
                }
            } else if zeros == ones {
                count++
                // fmt.Printf("0: %v, 1: %v, count: %v - %v-c\n", zeros, ones, count, s[i:j])
                break
            } else {
                if s[j] == '0' {
                    zeros++
                    if zeros > ones {
                        // fmt.Printf("0: %v, 1: %v, count: %v - %v\n", zeros, ones, count, s[i:j])
                        break
                    }
                } else {
                    ones++
                    if ones > zeros {
                        // fmt.Printf("0: %v, 1: %v, count: %v - %v\n", zeros, ones, count, s[i:j])
                        break
                    }
                }
            }
        }
    }
    
    return count
}
