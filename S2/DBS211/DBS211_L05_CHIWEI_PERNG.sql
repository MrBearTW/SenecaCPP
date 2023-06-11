/*
 DBS211 - Lab 5
 CHI-WEI PERNG
 121967228
 Jun 10, 2023
 Lab 5 Submission
 */

SET AUTOCOMMIT ON; 

-- Part A (DDL) :
-- 1.	Create table the following tables and their given constraints:

-- L5_MOVIES (movieid:int, title:varchar(35), year:int, director:int,score:decimal(3,2))	

CREATE TABLE L5_MOVIES  (
    movieid INT PRIMARY KEY,
    title VARCHAR(35) NOT NULL,
    releaseYear INT NOT NULL,
    director INT NOT NULL,
    score DECIMAL(3,2),  
    CONSTRAINT score_movies_CK CHECK (score <= 5 AND score >= 0)
);

-- L5_ACTORS (actorid:int, name:varchar(20), lastname:varchar(30))	
CREATE TABLE L5_ACTORS (
    actorid INT PRIMARY KEY,
    firstName VARCHAR(20) NOT NULL,
    lastname VARCHAR(30) NOT NULL
);

-- L5_CASTINGS (movieid:int, actorid:int)
CREATE TABLE L5_CASTINGS (
    movieid INT,
    actorid INT,
    CONSTRAINT castings_PK PRIMARY KEY (movieid, actorid),
    CONSTRAINT movieid_castings_FK FOREIGN KEY (movieid)
        REFERENCES L5_MOVIES (movieid),
    CONSTRAINT actorid_castings_FK FOREIGN KEY (actorid)
        REFERENCES L5_ACTORS (actorid)
);

-- L5_DIRECTORS(id:int, name:varchar(20), lastname:varchar(30))
CREATE TABLE L5_DIRECTORS (
    directorid INT PRIMARY KEY,
    firstName VARCHAR(20) NOT NULL,
    lastname VARCHAR(30) NOT NULL
);

-- 2.	Modify the movies table to create a foreign key constraint that refers to table directors. 
ALTER TABLE L5_MOVIES 
    ADD CONSTRAINT directorid_movies_FK FOREIGN KEY (director)
    REFERENCES L5_DIRECTORS (directorid);

-- 3.	Modify the movies table to create a new constraint so the uniqueness of the movie title is guaranteed. 
ALTER TABLE L5_MOVIES 
    ADD CONSTRAINT title_movies_UK UNIQUE (title);

-- 4.	Write insert statements to add the following data to table directors and movies.

-- Director
INSERT ALL  
   INTO L5_DIRECTORS VALUES  (1010, 'Rob', 'Minkoff')
   INTO L5_DIRECTORS VALUES  (1020, 'Bill', 'Condon')
   INTO L5_DIRECTORS VALUES  (1050, 'Josh', 'Cooley')
   INTO L5_DIRECTORS VALUES  (2010, 'Brad', 'Bird')
   INTO L5_DIRECTORS VALUES  (3020, 'Lake', 'Bell')
SELECT * FROM dual;

-- Movies
INSERT ALL  
   INTO L5_MOVIES VALUES  (100, 'The Lion King', 2019, 3020, 3.50)
   INTO L5_MOVIES VALUES  (200, 'Beauty and the Beast', 2017, 1050, 4.20)
   INTO L5_MOVIES VALUES  (300, 'Toy Story 4', 2019, 1020, 4.50)
   INTO L5_MOVIES VALUES  (400, 'Mission Impossible', 2018, 2010, 5.00)
   INTO L5_MOVIES VALUES  (500, 'The Secret Life of Pets', 2016, 1010, 3.90)
SELECT * FROM dual;

-- 5.	Write SQL statements to remove all above tables. 
DROP TABLE L5_CASTINGS;
DROP TABLE L5_MOVIES;
DROP TABLE L5_ACTORS;
DROP TABLE L5_DIRECTORS;

-- Is the order of tables important when removing? Why? 

-- YES, because the tables are linked together by foreign keys. If we remove the parent table first, the child table will not be able to find the parent table and will cause an error.

-- Part B (More DML):
-- 6.	Create a new empty table employee2 the same as table employees.  Use a single statement to create the table and insert the data at the same time.
CREATE TABLE employee2 AS
(SELECT * FROM employees);

-- 7.	Modify table employee2 and add a new column username to this table. The value of this column is not required and does not have to be unique.
ALTER TABLE employee2
    ADD username VARCHAR(20);

-- 8.	Delete all the data in the employee2 table
DELETE FROM employee2;

-- 9.	Re-insert all data from the employees table into your new table employee2 using a single statement. 
INSERT INTO employee2 (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle) 
(SELECT * FROM employees);

-- 10.	In table employee2, write a SQL statement to change the first name and the last name of employee with ID 1002 to your name. 
UPDATE employee2
SET firstname = 'ChiWei', lastname = 'Perng'
WHERE employeenumber = 1002;

-- 11.	In table employee2, generate the email address for column username for each student by concatenating the first character of employee’s first name and the employee’s last name. For instance, the username of employee Peter Stone will be pstone. NOTE: the username is in all lower case letters.  
-- Delete space in the first name
UPDATE employee2
SET username = LOWER(CONCAT(SUBSTR(firstname, 1, 1), lastname));

-- 12.	In table employee2, remove all employees with office code 4. 
DELETE FROM employee2
WHERE officecode = 4;

-- 13.	Drop table employee2. 
DROP TABLE employee2;