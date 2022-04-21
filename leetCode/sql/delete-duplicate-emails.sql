# https://leetcode.com/problems/delete-duplicate-emails
delete p1 from person p1
inner join person p2
where p1.email = p2.email and p1.id > p2.id;
