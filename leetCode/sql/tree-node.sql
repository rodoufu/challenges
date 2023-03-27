# https://leetcode.com/problems/tree-node
# Write your MySQL query statement below
select
    id,
    CASE
        WHEN p_id is null THEN 'Root'
        WHEN Not Exists (select 1 from Tree t2 Where t2.p_id = t1.id) THEN "Leaf"
        ELSE "Inner"
    END as type
from
    Tree t1
;
