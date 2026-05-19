

Q1. Create a table called Employee &amp; execute the following.
Employee(EMPNO, ENAME, JOB, MANAGER_NO, SAL, COMMISSION)
1. Create a USER and GRANT all permissions to the USER.
2. INSERT the any three records in the Employee table contains attributes
EMPNO, ENAME, JOB, MANAGER_NO, SAL, COMMISSION and use ROLLBACK.
Check the result.
3. Add PRIMARY KEY constraint and NOT NULL constraint to the employee table.
4. INSERT NULL values to the Employee table and verify the result.

CREATING TABLE:
CREATE TABLE Q1_EMPLOYEE(EMPNO INT,
ENAME VARCHAR(30),
JOB VARCHAR(30),
MANAGER_NO INT,
SAL DECIMAL(8,2),
COMMISSION DECIMAL(6,2)) ;
1. CREATING USER:
CREATE USER IF NOT EXISTS &#39;usn&#39;@&#39;localhost&#39; IDENTIFIED BY &#39;usn&#39;;
LIST USERS:
SELECT user,host FROM mysql.user;
GRANT PERMISSION
GRANT ALL PRIVILEGES ON BCS403.* TO &#39;usn&#39;@&#39;localhost&#39;;
2.INSERTING VALUES;
INSERT INTO Q1_EMPLOYEE VALUES(101, &#39;BHUVAN DASS&#39;,&#39;TEAM
LEADER&#39;,NULL,85000.00,2250.00);
INSERT INTO Q1_EMPLOYEE VALUES(102, &#39;ANIL ROSS&#39;,&#39;S/W
ENGINEER&#39;,NULL,85000.00,2250.00);
INSERT INTO Q1_EMPLOYEE VALUES(103, &#39;CHETAN RAM&#39;,&#39;S/W
ENGINEER&#39;,101,85000.00,2750.00);
INSERT INTO Q1_EMPLOYEE VALUES(104, &#39;BHAGAT RAJ&#39;,&#39;S/W TEST
ENGINEER&#39;,101,85000.00,2750.00);
INSERT INTO Q1_EMPLOYEE VALUES(105, &#39;ANIL ROSS&#39;,&#39;S/W
ENGINEER&#39;,NULL,85000.00,2250.00);
TURN OFF THE AUTOCOMMIT FEATURE OF SQL

SET AUTOCOMMIT=0;
INSERT VALUES;
INSERT INTO Q1_EMPLOYEE VALUES(106, &#39;YOGA RAJ&#39;,&#39;S/W
DEVELOPER&#39;,NULL,65000.00,2150.00);

DELETE FROM q1_employee WHERE EMPNO=105;
ROLLBACK;
3.ADDING PRIMARY KEY AND NOT NULL CONSTRAINTS:
ALTER TABLE Q1_EMPLOYEE ADD CONSTRAINT pk_primary_key_empno
PRIMARY KEY(EMPNO);
ALTER TABLE Q1_EMPLOYEE MODIFY JOB VARCHAR(30) NOT NULL;
4. INSERT INTO Q1_EMPLOYEE VALUES(107, &#39;YOGA RAJ&#39;, NULL, NULL,
65000.00, 2150.00);



Q2. Create a table called Employee that contain attributes EMPNO, ENAME, JOB,
MGR, SAL and execute the following.
1. Add a column COMMISSION with domain to the Employee Table.
2. Insert any five records into the table.
3. Update the column details of JOB
4. Rename the column of Employee table using ALTER command.
5. Delete the Employee whose EmpNo is 105.

CREATING TABLE:
CREATE TABLE Q2_EMPLOYEE(EMPNO INT PRIMARY KEY,
ENAME VARCHAR(30),
JOB VARCHAR(30),
MGR INT,
SAL DECIMAL(8,2)) ;
ALTER TABLE Q2_EMPLOYEE ADD CONSTRAINT MGR_REF_EMP
FOREIGN KEY(MGR) REFERENCES Q2_EMPLOYEE (EMPNO) ON
DELETE SET NULL;

1. ALTER TABLE Q2_EMPLOYEE ADD COLUMN COMMISSION
DECIMAL(6,2);
2. INSERT INTO Q2_EMPLOYEE VALUES(101, &#39;BHUVAN DASS&#39;,&#39;TEAM
LEADER&#39;,NULL,85000.00,2250.00);
INSERT INTO Q2_EMPLOYEE VALUES(102, &#39;ANIL ROSS&#39;,&#39;S/W
ENGINEER&#39;,NULL,85000.00,2250.00);
INSERT INTO Q2_EMPLOYEE VALUES(103, &#39;CHETAN RAM&#39;,&#39;S/W
ENGINEER&#39;,101,85000.00,2750.00);
INSERT INTO Q2_EMPLOYEE VALUES(104, &#39;BHAGAT RAJ&#39;,&#39;S/W TEST
ENGINEER&#39;,101,85000.00,2750.00);
INSERT INTO Q2_EMPLOYEE VALUES(105, &#39;ANIL ROSS&#39;,&#39;S/W
ENGINEER&#39;,NULL,85000.00,2250.00);
3. UPDATE Q2_EMPLOYEE SET JOB=&#39;Sr. S/W ENGINEER&#39; WHERE
EMPNO = 103;

4. ALTER TABLE Q2_EMPLOYEE RENAME COLUMN MGR TO MGR_NO;
5. DELETE FROM Q2_EMPLOYEE WHERE EMPNO=105;

Q3. Queries using aggregate functions(COUNT,AVG,MIN,MAX,SUM),Group by,
Orderby.
Employee(e_id, e_name, age, salary)
1. Create Employee table containing all Records e_id, e_name, age, salary.
2. Count number of employee names from employee table
3. Find the Maximum age from employee table.
4. Find the Minimum age from employee table.
5. Find salaries of employee in Ascending Order.
6. Find grouped salaries of employees.

1. CREATE TABLE Q3_EMPLOYEE(
e_id INT PRIMARY KEY,
e_name VARCHAR(30),
age INT,
salary DECIMAL(8,2)
);
INSERT INTO Q3_EMPLOYEE VALUES(1001, &#39;ANAND
MILIND&#39;,28,75000.00),(1002,&#39;MANOHAR MENON&#39;,30, 85000.00),
(1003,&#39;BHARATH MEENA&#39;,26,65000.00),(1004,&#39;ADNAN SAHU&#39;,34,55000.00),
(1005,&#39;MANI VELAN&#39;,32,75000.00),(1006,&#39;SUMAN NATH&#39;,30, 85000.00),
(1007,&#39;YASH PAUL&#39;,30, 65000.00);
2. SELECT COUNT(*) FROM Q3_EMPLOYEE;
3. SELECT MAX(age) AS &#39;max_age&#39; FROM Q3_EMPLOYEE;
4. SELECT MIN(age) AS &#39;min_age&#39; FROM Q3_EMPLOYEE;
5. SELECT * FROM Q3_EMPLOYEE ORDER BY salary;
6. SELECT salary, COUNT(e_id) AS emp_count FROM Q3_EMPLOYEE
GROUP BY salary;


Q4. Create a row level trigger for the customers table that would fire for INSERT or
UPDATE or DELETE operations performed on the CUSTOMERS table. This trigger
will display the salary difference between the old &amp; new Salary.
CUSTOMERS(ID,NAME,AGE,ADDRESS,SALARY)
CREATE TABLE CUSTOMER (cust_id INT, cust_name VARCHAR(30), cust_age
TINYINT, cust_address VARCHAR(30), salary DECIMAL(8,2));
DESC CUSTOMER;

CREATE ANOTHER TABLE SAME STRUCTURE AS OF THAT OF CUSTOMER
CREATE TABLE DUP_CUSTOMER (cust_id INT, cust_name VARCHAR(30),
cust_age TINYINT, cust_address VARCHAR(30), salary DECIMAL(8,2));
DESC DUP_CUSTOMER;

CREATE TRIGGER FOR INSERT:
CREATE TRIGGER INS_CUST_TRIGGER BEFORE INSERT ON CUSTOMER
FOR EACH ROW INSERT INTO DUP_CUSTOMER VALUES(NEW. cust_id, NEW.
cust_name, NEW. cust_age, NEW. cust_address, NEW. Salary);

Now, insert values to CUSTOMER tables and verify these values are inserted into
DUP_CUSTOMER table

INSERT INTO customer VALUES(1001,&#39;AMAR NATH&#39;,35,&#39;Kundapura&#39;,45000.00);
SELECT * FROM customer;

SELECT * FROM dup_customer;

TO SET THE DELIMITER TO ANY OTHER OTHER THAN “;”
DELIMITER //
CREATE TRIGGER FOR UPDATE:
CREATE TRIGGER UPD_CUST_SALARY1
AFTER UPDATE ON customer
FOR EACH ROW
BEGIN
DECLARE sal_diff DECIMAL(8,2);
SET @sal_diff = NEW.salary - OLD.salary;
END;
TYPE // and Press Enter Key
SET THE DELIMITER BACK TO “;”
TYPE DELIMITER ; and Press Enter Key
Update the Salary of the Customer and verify the results
UPDATE customer SET salary=50000.00 WHERE cust_id=1001;
SELECT * FROM customer;

SELECT @sal_diff AS SALARY_DIFFERENCE;

CREATE TRIGGER FOR DELETE:
CREATE TRIGGER CUST_DELETE BEFORE DELETE ON customer FOR EACH
ROW INSERT INTO DUP_CUSTOMER VALUES(OLD. cust_id, OLD. cust_name,
OLD. cust_age, OLD. cust_address, OLD. Salary);
DELETE FROM CUSTOMER WHERE CUST_ID=1001;
VERIFY THE RESULTS WITH THE FOLLOWING QUERIES;
SELECT * FROM customer;
SELECT * FROM dup_customer;



Q5. Create cursor for Employee table &amp; extract the values from the table. Declare
the variables, Open the cursor &amp; extract the values from the cursor. Close the cursor.
Employee(e_id, e_name, age, salary)
1. CREATE TABLE:
CREATE TABLE employee(e_id INT,
e_name VARCHAR(30),
e_age INT,
e_salary DECIMAL(10,2));
INSERT INTO employee VALUES(1001, &#39;Sunny Deol&#39;,25,85000.00),
(1002,&#39;Mohan Lal&#39;,28,95000.00),
(1003,&#39;Yoga Raj&#39;,28,95000.00);
2. Create a Stored Procedure with Cursor
DELIMITER //
CREATE PROCEDURE fetch_employee_data()
BEGIN
-- Declare variables to store cursor values
DECLARE emp_id INT;
DECLARE emp_name VARCHAR(255);
DECLARE emp_age INT;
DECLARE emp_salary DECIMAL(10, 2);
-- Declare a cursor for the Employee table
DECLARE emp_cursor CURSOR FOR
SELECT E_id, E_name, E_Age, E_Salary
FROM Employee;
-- Declare a continue handler for the cursor
DECLARE CONTINUE HANDLER FOR NOT FOUND
SET @finished = 1;
-- Open the cursor
OPEN emp_cursor;
-- Initialize a variable to control cursor loop
SET @finished = 0;
-- Loop through the cursor results
cursor_loop: LOOP
-- Fetch the next row from the cursor into variables
FETCH emp_cursor INTO emp_id, emp_name, emp_age, emp_salary;

-- Check if no more rows to fetch
IF @finished = 1 THEN
LEAVE cursor_loop;
END IF;
-- Output or process each row (for demonstration, print the values)
SELECT CONCAT(&#39;Employee ID: &#39;, emp_id, &#39;, Name: &#39;, emp_name, &#39;, Age: &#39;,
emp_age, &#39;, Salary: &#39;, emp_salary) AS Employee_Info;
END LOOP;
-- Close the cursor
CLOSE emp_cursor;
END//
DELIMITER ;
3. Execute the Stored Procedure
mysql&gt; CALL fetch_employee_data();

6.Write a PL/SQL block of code using parameterized Cursor, that will merge the
data available in the newly created table N_RollCall with the data available in
the table O_RollCall. If the data in the first table already exist in the second
table then that data should be skipped.
-- Create N_RollCall table
CREATE TABLE N_RollCall (
student_id INT PRIMARY KEY,
student_name VARCHAR(255),
birth_date DATE
);
-- Create O_RollCall table with common data
CREATE TABLE O_RollCall (
student_id INT PRIMARY KEY,
student_name VARCHAR(255),
birth_date DATE
);
mysql&gt; INSERT INTO O_RollCall (student_id, student_name, birth_date)
VALUES(1, &#39;Shivanna&#39;, &#39;1995-08-15&#39;), (3, &#39;Cheluva&#39;, &#39;1990-12-10&#39;);
insert some sample data into the N_RollCall table, including records that are common
with O_RollCall:
mysql&gt; INSERT INTO N_RollCall (student_id, student_name, birth_date)
VALUES
(1, &#39;Shiv&#39;, &#39;1995-08-15&#39;), -- Common record with O_RollCall
(2, &#39;Raj&#39;, &#39;1998-03-22&#39;),
(3, &#39;Sindu&#39;, &#39;1990-12-10&#39;), -- Common record with O_RollCall
(4, &#39;Neha&#39;, &#39;2000-05-18&#39;),
(5, &#39;Eshwari&#39;, &#39;1997-09-03&#39;);
Define the Stored Procedure
DELIMITER //
CREATE PROCEDURE merge_rollcall_data()
BEGIN
DECLARE done INT DEFAULT FALSE;
DECLARE n_id INT;
DECLARE n_name VARCHAR(255);
DECLARE n_birth_date DATE;
-- Declare cursor for N_RollCall table
DECLARE n_cursor CURSOR FOR
SELECT student_id, student_name, birth_date
FROM N_RollCall;
-- Declare handler for cursor
DECLARE CONTINUE HANDLER FOR NOT FOUND
SET done = TRUE;

-- Open the cursor
OPEN n_cursor;
-- Start looping through cursor results
cursor_loop: LOOP
-- Fetch data from cursor into variables
FETCH n_cursor INTO n_id, n_name, n_birth_date;
-- Check if no more rows to fetch
IF done THEN
LEAVE cursor_loop;
END IF;
-- Check if the data already exists in O_RollCall
IF NOT EXISTS (
SELECT 1
FROM O_RollCall
WHERE student_id = n_id
) THEN
-- Insert the record into O_RollCall
INSERT INTO O_RollCall (student_id, student_name, birth_date)
VALUES (n_id, n_name, n_birth_date);
END IF;
END LOOP;
-- Close the cursor
CLOSE n_cursor;
END//
DELIMITER ;

. Execute the Stored Procedure
mysql&gt; CALL merge_rollcall_data();

Verify Records in O_RollCall
mysql&gt; SELECT * FROM O_RollCall;
