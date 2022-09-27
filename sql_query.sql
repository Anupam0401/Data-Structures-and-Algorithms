-- your query should return the number of rows from your table where FirstName contains "e" and LastName has more than 5 characters. Your output should look like the following table.
SELECT * FROM maintable_OGE2G WHERE FirstName LIKE '%e%' AND LENGTH(LastName) > 5;
-- count the entries in the table
SELECT COUNT(*) FROM maintable_OGE2G WHERE FirstName LIKE '%e%' AND LENGTH(LastName) > 5;