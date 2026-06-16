// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut min_price = prices[0];
        let mut max_profit = 0;

        for i in 1..prices.len() {
            min_price = min_price.min(prices[i]);

            let profit = prices[i] - min_price;

            max_profit = max_profit.max(profit);
        }

        max_profit
    }
}
