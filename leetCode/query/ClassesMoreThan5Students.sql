# https://leetcode.com/problems/classes-more-than-5-students/
# Write your MySQL query statement below
select
    c.class
from
    (select distinct student, class from courses) c
group by
    c.class
having
    count(*) >= 5
;
