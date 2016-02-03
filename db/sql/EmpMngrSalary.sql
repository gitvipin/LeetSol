/*
Solution for : https://leetcode.com/problems/employees-earning-more-than-their-managers/
*/

/*
Best tutorial that explains this is 
https://lagunita.stanford.edu/courses/DB/SQL/SelfPaced/courseware/ch-sql/seq-vid-table_variables_and_set_operators/ @ 3:44
*/
select E.Name
from Employee E , Employee M
where E.ManagerId = M.Id and E.Salary > M.Salary
