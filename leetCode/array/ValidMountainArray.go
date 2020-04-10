// https://leetcode.com/problems/valid-mountain-array/
func validMountainArray(A []int) bool {
    lenA := len(A);
    if (lenA < 3) {
        return false;
    }
    
    hill := false;
    //fmt.Printf("%d %d\n", 0, A[0])
    
    if A[0] > A[1] {
        return false;
    }
    
    for i := 1; i < lenA - 1; i++ {
        //fmt.Printf("%d %d\n", i, A[i])
        if (A[i - 1] == A[i] || A[i] == A[i + 1]) {
            //fmt.Printf("%d %d\n ==", i, A[i])
            return false;
        }
        if A[i - 1] < A[i] && A[i] > A[i + 1] {
            if hill {
                //fmt.Printf("%d %d < > hill\n", i, A[i])
                return false;
            }
            hill = true;
        } else if A[i - 1] < A[i] && hill {
            //fmt.Printf("%d %d < hill\n", i, A[i])
            return false;
        } else if A[i] > A[i + 1] && !hill {
            //fmt.Printf("%d %d\n > hill", i, A[i])
            return false;
        }
    }
    
    if hill && A[lenA - 2] < A[lenA - 1] {
        return false;
    }
    
    return hill;
}
