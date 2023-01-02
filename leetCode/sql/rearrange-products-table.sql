# https://leetcode.com/problems/rearrange-products-table/
# Write your MySQL query statement belowstoas
select product_id, 'store1' as store , store1 as price from products where store1 is not null 
union all
Select product_id, 'store2', store2 from Products where store2 is not null 
union all 
Select product_id, 'store3', store3 from Products where store3 is not null
