-- EMPLOYEE

-- empid          empname           managerid           deptid      salary            DOB  
-- 1                      emp 1                      0                         1           6000         1982-08-06  
-- 2                      emp 2                      0                         5           6000         1982-07-11  
-- 3                      emp 3                      1                         1           2000         1983-11-21
-- 13                   emp 13                     2                         5          2000          1984-03-09  
-- 11                   emp 11                     2                         1          2000          1989-07-23 
-- 9                     emp 9                       1                         5          3000          1990-09-11  
-- 8                     emp 8                       3                         1          3500          1990-05-15  
-- 7                     emp 7                       2                         5          NULL         NULL  
-- 3                     emp 3                       1                         1          2000         1983-11-21  
  
-- DEPARTMENT TABLE 
 
-- deptid            deptname  
-- 1                         IT  
-- 5                        Admin  

-- Write a SQL query to print department name along with department wise average salary

SELECT deptname,AVG(salary) FROM EMPLOYEE E,DEPARTMENT D WHERE E.deptid=D.deptid GROUP BY deptname;

-- Write a SQL query to print oldest employee name department wise along with department name.

SELECT deptname,empname FROM EMPLOYEE E,DEPARTMENT D WHERE E.deptid=D.deptid AND DOB=(SELECT MIN(DOB) FROM EMPLOYEE E1 WHERE E1.deptid=E.deptid);

-- Write a SQL query to delete duplicate rows in Employee table. Note that the column empid should be used to uniquely identify a row.

DELETE FROM EMPLOYEE WHERE empid NOT IN (SELECT MIN(empid) FROM EMPLOYEE GROUP BY empname);



