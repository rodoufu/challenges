# https://leetcode.com/problems/managers-with-at-least-5-direct-reports
select
    name
from
    Employee e
where
    5 <= (select count(*) from Employee e2 where e2.managerId = e.id)
;
