// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/
class Solution {
public:
    int numberOfSteps (int num) {
        int count = 0;
        
        while (num) {
            //printf("%d, %d\n", num, count);
            if (num % 2 == 1) {
                --num;
            } else {
                num /= 2;
            }

            ++count;
        }
        
        return count;
    }
};
