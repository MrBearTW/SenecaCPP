/*
 DBS211 - Lab 3
 CHI-WEI PERNG
 121967228
 May 28, 2023
 Lab 3 Submission
 */
SET AUTOCOMMIT ON;

-- 1. Display the data for all offices.
SELECT *
FROM offices;

-- 2. Display the employee number for all employees whose office code is 1.
SELECT *
FROM employees
WHERE officecode = 1;

-- 3. Display customer number, customer name, contact first name and contact last name, and phone for all customers in Paris. (hint: be wary of case sensitivity)
SELECT customernumber,
    customername,
    contactfirstname,
    contactlastname,
    phone
FROM customers
WHERE city = 'Paris';

/*
 4. Repeat the previous Query with a couple small changes:
 - The contact’s first and last name should be in a single column in the format “lastname, firstname”.
 - Show customers who are in Canada
 */
SELECT customernumber,
    customername,
    TRIM(contactlastname) || ',' || TRIM(contactfirstname) AS fullname,
    phone
FROM customers
WHERE country = 'Canada';

-- 5. Display customer number for customers who have payments. Do not included any repeated values. (hints: how do you know a customer has made a payment? You will need to access only one table for this query)
SELECT DISTINCT customernumber
FROM payments;

-- 6. List customer numbers, check number, and amount for customers whose payment amount is not in the range of $30,000 to $65,000. Sort the output by top payments amount first.
SELECT customernumber,
    checknumber,
    amount
FROM payments
WHERE amount NOT BETWEEN 30000 AND 65000
ORDER BY amount DESC;

-- 7. Display the order information for all orders that are cancelled.
SELECT *
FROM orders
WHERE status = 'Cancelled';

/*
 8. The company needs to know the percentage markup for each product sold. Produce a query that outputs the ProductCode, ProductName, BuyPrice, MSRP in addition to
 - The difference between MSRP and BuyPrice (i.e. MSRP-BuyPrice) called markup 
 - The percentage markup (100 * calculated by difference / BuyPrice) called percmarkup rounded to 1 decimal place.
 */
SELECT productcode,
    productname,
    buyprice,
    msrp,
    msrp - buyprice AS markup,
    ROUND((100 * (msrp - buyprice) / buyprice), 1) AS percmarkup
FROM products;

-- 9. Display the information of all products with string ‘co’ in their product name. (c and o can be lower or upper case).
SELECT *
FROM products
WHERE UPPER(productname) LIKE '%CO%';

-- 10. Display all customers whose contact first name starts with letter s (both lowercase and uppercase) and includes letter e (both lowercase and uppercase).
SELECT *
FROM customers
WHERE UPPER(SUBSTR(contactfirstname, 1, 1)) = 'S'
    AND UPPER(contactfirstname) LIKE '%E%';

/*
11. Create a statement that will insert yourself as an employee of the company.
- Use a unique employee number of your choice
- Use your school email address
- Your job title will be “Cashier”
- Office code will be 4
- You will report to employee 1088
*/
INSERT INTO employees (
        employeenumber,
        lastname,
        firstname,
        extension,
        email,
        jobtitle,
        officecode,
        reportsto
    )
VALUES (
        1703,
        'Djarin',
        'Din',
        'x5566',
        'cperng@myseneca.ca',
        'Cashier',
        4,
        1088
    ) ;

-- 12. Create a query that displays your, and only your, employee data
SELECT *
FROM employees
WHERE employeenumber = 1703;

-- 13. Create a statement to update your job title to “Head Cashier”
UPDATE employees
SET jobtitle = 'Head Cashier'
WHERE employeenumber = 1703 ;

-- 14. Create a statement to insert another fictional employee into the database. This employee will be a “Cashier” and will report to you. Make up fake data for the other fields.
INSERT INTO employees (
        employeenumber,
        lastname,
        firstname,
        extension,
        email,
        jobtitle,
        officecode,
        reportsto
    )
VALUES (
        1705,
        'Frodo',
        'Baggins',
        'x5567',
        'ring@myseneca.ca',
        'Cashier',
        4,
        1703
    );

-- 15. Create a statement to Delete yourself from the database. Did it work? If not, why?
DELETE FROM employees
WHERE employeenumber = 1703;
/*
Fail to delete.
This violate Referential Integrity --> You can not delete a parent record while children exist.
*/

-- 16. Create a statement to delete the fake employee from the database and then rerun the statement to delete yourself. Did it work?
DELETE FROM employees
WHERE employeenumber = 1705;
DELETE FROM employees
WHERE employeenumber = 1703;
/*
Yes, two row got delete.
Because when delete the fake employee(1705), noone is report to me(1703), so my row could be delete.
*/

-- 17. Create a single statement that will insert both yourself and the fake employee at the same time. This time the fake employee will report to 1088 as well.
INSERT ALL 
INTO employees VALUES (
        1703,
        'Djarin',
        'Din',
        'x5566',
        'cperng@myseneca.ca',
        4,
        1088,
        'Cashier'
    ) 
INTO employees VALUES (
        1705,
        'Frodo',
        'Baggins',
        'x5567',
        'ring@myseneca.ca',
        4,
        1088,
        'Cashier'
    )
SELECT * FROM dual;

-- 18. Create a single statement to delete both yourself and the fake employee.
DELETE FROM employees
WHERE employeenumber = 1703 OR employeenumber = 1705;
