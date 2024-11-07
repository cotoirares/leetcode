/* Write your T-SQL query statement below */
SELECT firstName, lastName, city, state
From Address Right outer Join Person on Address.personID = Person.personID
