#define WHILE_MUL(X, M) while((X) % (M) == 0) (X) /= (M)
class Solution {
public:
    bool isUgly(int num) {
        if (num <= 0) {
            return false;
        }
        WHILE_MUL(num, 30);
        WHILE_MUL(num, 15);
        WHILE_MUL(num, 10);
        WHILE_MUL(num, 2);
        WHILE_MUL(num, 3);
        WHILE_MUL(num, 5);
        
        return num == 1;
    }
};
