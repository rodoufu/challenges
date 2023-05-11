# https://leetcode.com/problems/employee-bonus
select
    name,
    bonus
from
    employee e left join bonus b on e.empId = b.empId
where
    bonus is null 
    or bonus < 1000
;
