# https://leetcode.com/problems/employees-whose-manager-left-the-company
select
    employee_id
from
    Employees e
where
    salary < 30000
    and manager_id not in (select employee_id from Employees)
order by employee_id
;
