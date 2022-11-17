// https://leetcode.com/problems/guess-number-higher-or-lower/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guessNumber(n int) int {
    l := 1
    r := n
    
    for {
        mid := l + (r - l) / 2
        guessResp := guess(mid)
        //fmt.Printf("l: %v, mid: %v, r: %v, guessResp: %v\n", l, mid, r, guessResp)
        
        switch guessResp {
            case -1:
                r = mid - 1
            case 0:
                return mid
            case 1:
                l = mid + 1
        }
    }
    
}
