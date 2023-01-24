# https://leetcode.com/problems/reformat-department-table/
# Write your MySQL query statement below
select distinct
    d.id,
    jan.revenue as Jan_Revenue,
    feb.revenue as Feb_Revenue,
    mar.revenue as Mar_Revenue,
    apr.revenue as Apr_Revenue,
    may.revenue as May_Revenue,
    jun.revenue as Jun_Revenue,
    jul.revenue as Jul_Revenue,
    aug.revenue as Aug_Revenue,
    sep.revenue as Sep_Revenue,
    oct.revenue as Oct_Revenue,
    nov.revenue as Nov_Revenue,
    dece.revenue as Dec_Revenue
from
    Department d
    left join Department jan on (d.id = jan.id and jan.month = 'Jan')
    left join Department feb on (d.id = feb.id and feb.month = 'Feb')
    left join Department mar on (d.id = mar.id and mar.month = 'Mar')
    left join Department apr on (d.id = apr.id and apr.month = 'Apr')
    left join Department may on (d.id = may.id and may.month = 'May')
    left join Department jun on (d.id = jun.id and jun.month = 'Jun')
    left join Department jul on (d.id = jul.id and jul.month = 'Jul')
    left join Department aug on (d.id = aug.id and aug.month = 'Aug')
    left join Department sep on (d.id = sep.id and sep.month = 'Sep')
    left join Department oct on (d.id = oct.id and oct.month = 'Oct')
    left join Department nov on (d.id = nov.id and nov.month = 'Nov')
    left join Department dece on (d.id = dece.id and dece.month = 'Dec')
    
