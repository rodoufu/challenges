// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/
class Solution {
public:
    int subtractProductAndSum(int n) {
        if (!n) {
            return 0;
        }
        int prod = 1;
        int soma = 0;
        
        while (n) {
            prod *= n % 10;
            soma += n % 10;
            n /= 10;
        }
        
        return prod - soma;
    }
};
