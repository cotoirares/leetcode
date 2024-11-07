/* Write your T-SQL query statement below */
Select e.name as Employee
From Employee e
JOIN Employee m on e.managerId = m.Id
where e.salary > m.salary
