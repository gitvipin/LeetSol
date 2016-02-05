/*
Solution for : https://leetcode.com/problems/customers-who-never-order/
*/

// Solution 1 : using subquery
select Name
from Customers C
where Id not in (select CustomerId from Orders)
