# https://leetcode.com/problems/big-countries/submissions/
# Write your MySQL query statement below

select
    name,
    population,
    area
from
    World
where
    population > 25000000

union
select
    name,
    population,
    area
from
    World
where
    area > 3000000
;
