# Write your MySQL query statement below
# https://leetcode.com/problems/sales-person/
select
    s.name
from
    SalesPerson s
where
    not exists (
        select 
            1 
        from 
            orders o
            inner join company c on o.com_id = c.com_id
        where
            o.sales_id = s.sales_id
            and c.name = 'RED'
    )
;
