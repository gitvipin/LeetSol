/*
Solution for : https://leetcode.com/problems/duplicate-emails/
*/

/*
Use the slef join to find pairs which have same email but not the same id. 
Also use distinct to avoid duplicates. 
*/
select distinct P.Email
from Person P, Person Q
where P.Email = Q.Email and P.Id < Q.Id
