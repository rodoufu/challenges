# https://leetcode.com/problems/reformat-date/
class Solution:
    def reformatDate(self, date: str) -> str:
        month_to_value = {
            "Jan": "01",
            "Feb": "02",
            "Mar": "03",
            "Apr": "04",
            "May": "05",
            "Jun": "06",
            "Jul": "07",
            "Aug": "08",
            "Sep": "09",
            "Oct": 10,
            "Nov": 11,
            "Dec": 12,
        }
        day_str, month_str, year_str = date.split(' ')
        if len(day_str) == 3:
            day_str = f"0{day_str}"
        return f"{year_str}-{month_to_value[month_str]}-{day_str[:-2]}"
