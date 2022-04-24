# Write your MySQL query statement below
# https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/
select customer_number from ( 
select
    customer_number,
    count(*)
from
    orders
group by customer_number
order by 2 desc
limit 1
) a
;
