# https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution:
    def average(self, salary: List[int]) -> float:
        if len(salary) == 0:
            return 0
        max_salary = min_salary = salary[0]
        sum_salary = 0
        for sal in salary:
            min_salary = min(min_salary, sal)
            max_salary = max(max_salary, sal)
            sum_salary += sal
        
        sum_salary -= min_salary + max_salary

        return sum_salary / (len(salary) - 2)
