/*
    DBS211 - Lab 1
    CHI-WEI PERNG
    May 14, 2023
    Lab 1 Submission
*/


-- 1 - How many tables have been created? List the names of the created tables!
/*
8 tables were created.

CUSTOMERS
EMPLOYEES
OFFICES
ORDERDETAILS
ORDERS
PAYMENTS
PRODUCTLINES
PRODUCTS

ref: SELECT table_name FROM user_tables;
*/


-- 2 - Click on the table "customers". Click on the Data tab near the top of the worksheet. How many rows are there in the table customers?
/*
122 rows in table CUSTOMERS.

ref: SELECT COUNT(*) FROM CUSTOMERS;
*/

-- 3 - What SQL Statement would return the same results? Write the statement in the .sql file and execute it. You will learn how to select rows and columns from a table by writing SQL select statements later in this course.
/*
If the data hasn't been changed, use "SELECT" will return the same result.

ref: SELECT * FROM CUSTOMERS;
*/


-- 4 - How many columns does the customers table have?
/*
The CUSTOMERS table has 13 columns.

ref: SELECT count(*) FROM user_tab_cols WHERE table_name = 'CUSTOMERS';
*/

-- 5 - What is the value of each column in the first row in table customers? Write the column name and the column data type in addition to the value.
/*
CUSTOMERNUMBER  CUSTOMERNAME    CONTACTLASTNAME CONTACTFIRSTNAME    PHONE       ADDRESSLINE1    ADDRESSLINE2    CITY   STATE    POSTALCODE  COUNTRY SALESREPEMPLOYEENUMBER  CREDITLIMIT
103	            Atelier         graphique	    Schmitt	Carine 	    40.32.2555	54, rue Royale		            Nantes 		    44000	    France	1370	                21000

Name                   Null?    Type         
---------------------- -------- ------------ 
CUSTOMERNUMBER         NOT NULL NUMBER(38)   
CUSTOMERNAME           NOT NULL VARCHAR2(50) 
CONTACTLASTNAME        NOT NULL VARCHAR2(50) 
CONTACTFIRSTNAME       NOT NULL VARCHAR2(50) 
PHONE                  NOT NULL VARCHAR2(50) 
ADDRESSLINE1           NOT NULL VARCHAR2(50) 
ADDRESSLINE2                    VARCHAR2(50) 
CITY                   NOT NULL VARCHAR2(50) 
STATE                           VARCHAR2(50) 
POSTALCODE                      VARCHAR2(15) 
COUNTRY                NOT NULL VARCHAR2(50) 
SALESREPEMPLOYEENUMBER          NUMBER(38)   
CREDITLIMIT                     NUMBER(10,2) 


ref: 
SELECT * FROM CUSTOMERS WHERE ROWNUM = 1
DESC CUSTOMERS
*/


-- 6 - Write the number of rows and columns for the rest of the tables in your schema.  Make a basic text table in a comment block providing the number of rows and columns in each table. It might look something like this:
/*
Table Name    Rows    Columns
----------    ------  -------
CUSTOMERS       122     12
EMPLOYEES       23      8
OFFICES         7       9
ORDERDETAILS    2996    5
ORDERS          326     7
PAYMENTS        273     4
PRODUCTLINES    7       4
PRODUCTS        110     9
*/


-- 7 - Right Click on the orderdetails table and choose tables/count rows.  How many rows does the order details table include?
/*
Table ORDERDETAILS contains 2996 rowa.
*/


-- 8 - Write the following SQL statement such that it is executable and execute it.
/*
Name         Null?    Type         
------------ -------- ------------ 
OFFICECODE   NOT NULL VARCHAR2(10) 
CITY         NOT NULL VARCHAR2(50) 
PHONE        NOT NULL VARCHAR2(50) 
ADDRESSLINE1 NOT NULL VARCHAR2(50) 
ADDRESSLINE2          VARCHAR2(50) 
STATE                 VARCHAR2(50) 
COUNTRY      NOT NULL VARCHAR2(50) 
POSTALCODE   NOT NULL VARCHAR2(15) 
TERRITORY    NOT NULL VARCHAR2(10)
*/
describe offices;

-- 9 - Type the following statements in and execute them, then briefly describe what the statement is doing!
/*
SELECT * FROM employees;
Show all rows in table EMPLOYEES.

SELECT * FROM customers ORDER BY ContactLastName;
Show all rows in table CUSTOMERS and order by ContactLastName.

*/
SELECT * FROM employees;
SELECT * FROM customers ORDER BY ContactLastName;


-- 10 - How many constraints does the products table have?
/*
Table PRODUCTS has 11 constraints.
*/


-- 11 - What and where is the gutter? Describe its location in your solution file. Find a way to turn on line numbers on in the gutter.
/*
The gutter is the space before the vertical line on the left side of the editor.

To turn on line numbers in the gutter, you can right-click in the gutter and select “Toggle Line Numbers”.
Alternatively, you can go to Tools > Preferences > Code Editor > Line Gutter and check “Show Line Numbers”.
*/


-- 12 - Set the font size in the worksheet editor to a size that is best for you, state what size you chose in a comment block - (Hint: Tools/Preferences)
/*
I select 14 for my editor.
*/

