# https://leetcode.com/problems/day-of-the-year/
class Solution:
    def dayOfYear(self, date: str) -> int:
        month_days = {
            1: 31,
            2: 28,
            3: 31,
            4: 30,
            5: 31,
            6: 30,
            7: 31,
            8: 31,
            9: 30,
            10: 31,
            11: 30,
            12: 31,
        }
        year = int(date[:4])
        month = int(date[5:7])
        day = int(date[8:10])
        # print(f"{day}/{month}/{year}")
        
        resp = day
        
        for i in range(1, month):
            resp += month_days[i]
        
        return resp + (1 if year > 1900 and month > 2 and year % 4 == 0 else 0)
