# https://leetcode.com/problems/department-highest-salary/
# Write your MySQL query statement below
select
    sub.Department,
    e1.Name as Employee,
    sub.Salary
from
    (select
        d.id,
        d.Name as Department,
        max(Salary) as Salary
    from
        Department d join Employee e on d.id = e.DepartmentId
    group by
        d.id,
        d.Name
    ) sub join Employee e1 on e1.DepartmentId = sub.id and e1.Salary = sub.Salary
;
