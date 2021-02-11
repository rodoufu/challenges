# https://leetcode.com/problems/water-bottles/
class Solution:
    def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
        drink = 0
        while numBottles >= numExchange:
            mult = numBottles // numExchange
            numBottles -= numExchange * mult
            drink += numExchange * mult
            numBottles += mult
        drink += numBottles
        return drink
