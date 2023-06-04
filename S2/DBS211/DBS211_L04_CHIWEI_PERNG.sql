/*
 DBS211 - Lab 4
 CHI-WEI PERNG
 121967228
 Jun 3, 2023
 Lab 4 Submission
 */

-- Tasks:
-- Select data from multiple tables
-- 1. Create a query that shows employee number, first name, last name, city, phone number and postal code for all employees in France.
--  a. Answer this question using an ANSI-89 Join
SELECT employeenumber,
    firstname,
    lastname,
    city,
    phone,
    postalcode
FROM employees,
    offices
WHERE employees.officecode = offices.officecode
    AND city = 'Paris';

--  b. Answer this question using an ANSI-92 Join
SELECT employeenumber,
    firstname,
    lastname,
    city,
    phone,
    postalcode
FROM employees
    INNER JOIN offices ON employees.officecode = offices.officecode
WHERE city = 'Paris';

/*
2. Create a query that displays all payments made by customers from Canada.
Sort the output by Customer Number.
Only display the Customer Number, Customer Name, Payment Date and Amount.
Make sure the date is displayed clearly so the human knows what date it is correctly. (i.e. what date is 02-04-19??? – Feb 4, 2019, April 2, 2019, April 19, 2002, ….)
*/
SELECT customers.customernumber,
    customername,
    TO_CHAR(paymentdate, 'Mon dd, yyyy'),
    amount
FROM customers
    INNER JOIN payments ON customers.customernumber = payments.customernumber
WHERE UPPER(country) = 'CANADA'
ORDER BY customernumber;

-- 3. Create a query that shows all USA customers who have not made a payment. Display only the customer number and customer name sorted by customer number.
SELECT customers.customernumber,
    customername
FROM customers
    LEFT OUTER JOIN payments ON customers.customernumber = payments.customernumber
WHERE payments.customernumber IS NULL
    AND UPPER(country) = 'USA'
ORDER BY customers.customernumber;


-- Views and Joins

-- 4. a) Create a view (vwCustomerOrder) to list all orders with the following data for all customers:
--      Customer Number, Order number, order date, product name, quantity ordered, and price for each product in every order.
CREATE VIEW vwCustomerOrder AS
SELECT c.customernumber,
    o.ordernumber,
    TO_CHAR(orderdate, 'Mon dd, yyyy') AS orderdate,
    quantityordered,
    productName,
    priceeach
FROM customers c
    LEFT OUTER JOIN orders o ON c.customernumber = o.customernumber
    LEFT OUTER JOIN orderdetails od ON o.ordernumber = od.ordernumber
    LEFT OUTER JOIN products p ON p.productcode = od.productcode;

--  b) Write a statement to view the results of the view just created.
SELECT *
FROM vwCustomerOrder;

-- 5. Using the vwCustomerOrder view, display the order information for customer number 124. Sort the output based on order number and then order line number. (Yes, I know orderLineNumber is not in the view, that is the trick!)
SELECT vwo.*,
    od.orderlinenumber
FROM vwCustomerOrder vwo
    INNER JOIN orderdetails od ON vwo.ordernumber = od.ordernumber
WHERE customernumber = 124
ORDER BY vwo.ordernumber,
    od.orderlinenumber;

-- 6. Create a query that displays the customer number, first name, last name, phone, and credit limits for all customers who do not have any orders.
SELECT c.customernumber,
    contactlastname,
    contactfirstname,
    phone,
    creditlimit
FROM customers c
    LEFT OUTER JOIN orders o ON c.customernumber = o.customernumber
WHERE o.ordernumber IS NULL;

-- 7. Create a view (vwEmployeeManager) to display all information of all employees and the name and the last name of their managers if there is any manager that the employee reports to. Include all employees, including those who do not report to anyone.
CREATE VIEW vwEmployeeManager AS
SELECT e.*,
    m.firstname || ' ' || m.lastname AS manager
FROM employees e
    LEFT OUTER JOIN employees m on e.reportsto = m.employeenumber;

-- 8. Modify the employee_manager view so the view returns only employee information for employees who have a manager. Do not DROP and recreate the view – modify it. (Google is your friend).
CREATE OR REPLACE VIEW vwEmployeeManager AS
SELECT e.*,
    em.firstname || ' ' || em.lastname AS manager
FROM employees e,
    employees em
WHERE e.reportsto = em.employeenumber;

-- 9. Drop both customer_order and employee_manager views.
DROP VIEW vwCustomerOrder;
DROP VIEW vwEmployeeManager;