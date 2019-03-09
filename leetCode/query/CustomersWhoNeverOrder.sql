# https://leetcode.com/problems/customers-who-never-order/
# Write your MySQL query statement below
select
    Name as Customers
from
    Customers c
where
    not exists (
        select 1 from Orders o where o.CustomerId = c.Id
    )
;
