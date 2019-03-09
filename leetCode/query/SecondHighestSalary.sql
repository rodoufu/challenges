# https://leetcode.com/problems/second-highest-salary/
# Write your MySQL query statement below
SELECT
    CASE
        WHEN COUNT(DISTINCT(Employee.Salary)) >= 2 THEN (SELECT Salary FROM Employee ORDER BY Salary DESC LIMIT 1,1) 
        ELSE NULL
    END AS SecondHighestSalary
FROM
    Employee
;
