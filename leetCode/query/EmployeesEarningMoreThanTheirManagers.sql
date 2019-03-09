# https://leetcode.com/problems/employees-earning-more-than-their-managers/
# Write your MySQL query statement below
select
    e.Name as Employee
from
    Employee e
where
    exists (
        select 1 
        from
            Employee e1
        where e.ManagerId = e1.id and e.Salary > e1.Salary
    )
;
