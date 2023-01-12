# https://leetcode.com/problems/article-views-i/
select distinct author_id as id from views where author_id =viewer_id
order by 1;
