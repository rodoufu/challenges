// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        auto len = prices.size();
        if (len < 2) {
            return 0;
        }
        vector<int> menor, maior;
        menor.push_back(prices[0]);
        //maior.push_back(prices[0]);
        maior.push_back(prices[prices.size() - 1]);

        for (auto &x: prices) {
            menor.push_back(min(x, menor[menor.size() - 1]));
            //maior.push_back(max(x, maior[maior.size() - 1]));  
        }
        
        for (auto it = prices.rbegin(); it != prices.rend(); ++it) {
            maior.push_back(max(*it, maior[maior.size() - 1]));  
        }
        
        int resp = 0;
        {
            auto itS = menor.begin() + 1;
            auto itB = maior.rbegin() + 1;

            for (; itB != maior.rend(); ++itS, ++itB) {
                resp = max(resp, *itB - *itS);
            }
        }

        /*
        puts("menor");
        for (auto &x: menor) {
            printf("%d, ", x);
        }
        puts("\nmaior");
        maior = vector<int>(maior.rbegin(), maior.rend());
        for (auto &x: maior) {
            printf("%d, ", x);
        }
        puts("");
        */

        return resp;
    }
};
