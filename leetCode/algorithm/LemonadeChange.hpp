// https://leetcode.com/problems/lemonade-change/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five, ten;
        five = ten = 0;
        
        int i = 0;
        for (auto &x : bills) {
            // printf("i: %d, x: %d, f:%d, t:%d\n", i, x, five, ten);
            switch (x) {
                case 5:
                    ++five;
                    break;
                case 10:
                    if (!five) {
                        // printf("i: %d - 10 break\n", i);
                        return false;
                    }
                    --five;
                    ++ten;
                    break;
                case 20:
                    x = 15;
                    if (ten) {
                        --ten;
                        x -= 10;
                    }
                    while (x) {
                        if (five) {
                            --five;
                            x -= 5;
                        } else {
                            // printf("i: %d - 20 break\n", i);
                            return false;
                        }
                    }
                    break;
            }
            ++i;
        }
        
        return true;
    }
};
