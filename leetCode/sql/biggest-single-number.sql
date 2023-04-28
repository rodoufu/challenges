# https://leetcode.com/problems/biggest-single-number/
select * from (
(
    select
    num#,
    #count(*)
from
    MyNumbers
group by num
having count(*) = 1
order by num desc
limit 1
)
union
(select null)
) a
limit 1
