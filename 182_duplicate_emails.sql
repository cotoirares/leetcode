/* Write your T-SQL query statement below */
Select distinct e1.email as Email
from Person e1
Inner Join Person e2 on e1.email = e2.email
where e1.email = e2.email and e1.id < e2.id
