/* Write your T-SQL query statement below */
SELECT max(Salary) as SecondHighestSalary from Employee where Salary != (SELECT max(Salary) from Employee)
