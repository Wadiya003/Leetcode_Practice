# Write your MySQL query statement below
SELECT a.name As Employee FROM Employee a, Employee b WHERE a.ManagerId = b.Id AND a.Salary > b.Salary;