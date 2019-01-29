class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if (size == 0) {
            return 0;
        }
        int profit = 0;
        int min = prices[0];
        for (int i = 1; i < size - 1; i++) {
            min = min > prices[i] || min == -1 ? prices[i] : min;
            if (prices[i] > min && prices[i] > prices[i + 1]) {
                profit += prices[i] - min;
                min = -1;
            }
        }
        min = min > prices[size - 1] || min == -1 ? prices[size - 1] : min;
        if (prices[size - 1] > min) {
            profit += prices[size - 1] - min;
            min = -1;
        }
        return profit;
    }
};
