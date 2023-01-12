// https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/
func largestSumAfterKNegations(nums []int, k int) int {
    total := 0
    positive :=[]int {}
    negative:= []int {}
    fixV := func(isNeg bool){
        var p *[]int = &positive 
        if isNeg {
            p = & negative 
        }

        l := len(*p)

        
        for l >= 2 && ((isNeg && (*p)[l-1]>(*p)[l-2]) || (!isNeg && (*p)[l-1] >(*p)[l-2])) {
            (*p)[l-1], (*p)[l-2]=(*p)[l-2],(*p)[l-1]
            l--
        }
    }
    for _,x := range nums {
        total += x 
        if x >= 0{
            positive= append(positive, x)
            fixV(false)
        } else {
            negative= append(negative, x)
            fixV(true)
        }
    }

    for i :=0; i<  k; i++{
        //fmt.Printf("i:%v, t:%v, p:%v, n:%v\n", i, total, positive, negative)
        
        lneg := len(negative)
        if lneg>0{
            v:=negative [lneg-1]
            negative= negative [:lneg-1]
            total -=2*v 
            positive= append(positive,-v)
            fixV(false)
        } else {
            if (k - i) % 2 == 0{
                break 
            }
            lpo:=len(positive)
            v:=positive[lpo-1]
            total -=2*v 
            negative=append(negative,-v)
            fixV(true) 
            break

        }
    }
    
    return total
}
