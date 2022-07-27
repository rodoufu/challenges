# https://leetcode.com/problems/employees-with-missing-information
# Write your MySQL query statement below
select * from (
select employee_id from Employees e where not exists (select 1 from salaries s where s.employee_id = e.employee_id)
union
select employee_id from salaries s where not exists (select 1 from Employees e where e.employee_id = s.employee_id)
) ei
order by 1
