CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    IF @N < 1
        RETURN NULL;
    RETURN (
        SELECT DISTINCT salary 
        FROM Employee 
        ORDER BY salary DESC 
        OFFSET @N - 1 ROWS 
        FETCH NEXT 1 ROWS ONLY
    );
END;

