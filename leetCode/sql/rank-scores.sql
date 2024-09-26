# https://leetcode.com/problems/rank-scores
select
    score,
    dense_rank() over (order by score desc) as "rank"
from 
    Scores
order by 
    score desc
;
