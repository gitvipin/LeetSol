/*
Solution for : https://leetcode.com/problems/employees-earning-more-than-their-managers/
*/

select E.Name
from Employee E , Employee M
where E.ManagerId = M.Id and E.Salary > M.Salary
