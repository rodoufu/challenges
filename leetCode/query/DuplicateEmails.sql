# https://leetcode.com/problems/duplicate-emails/
# Write your MySQL query statement below
select distinct
    p1.Email
from
    Person p1 inner join Person p2 on p1.Email = p2.Email and p1.Id <> p2.Id
;
