# https://leetcode.com/problems/calculate-money-in-leetcode-bank/
class Solution:
    def totalMoney(self, n: int) -> int:
        deposit_monday = 0
        deposit = 0
        balance = 0
        for i in range(1, n + 1):
            if i % 7 == 1:
                deposit_monday += 1
                deposit = deposit_monday
            else:
                deposit += 1
            balance += deposit
        return balance
