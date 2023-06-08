/* **************
 CHI-WEI PERNG
 DBS211 - Week 5
 Intro to DDL
 June 7 2023
 ************** */
/*
 
 CREATE TABLE <tablename> (
 <filed name 1> <data type and size> <column constraint(s)>
 <filed name 2> <data type and size> <column constraint(s)>
 ...
 <filed name n> <data type and size> <column constraint(s)>  
 CONSTRAINT <constraint name> <CONSTRAINT TYPE> <constraint details>,
 CONSTRAINT <constraint name> <CONSTRAINT TYPE> <constraint details>,
 CONSTRAINT <constraint name> <CONSTRAINT TYPE> <constraint details>,
 );
 
 */
 
 -- Example
CREATE TABLE xPeople (
  personID INT PRIMARY KEY,
  lastname VARCHAR(25) NOT NULL,
  firstname VARCHAR(25) NOT NULL,
  dcb DATE,  -- Don't put NULL
  email VARCHAR(100) UNIQUE NOT NULL,
  prov CHAR(2) DEFAULT 'ON',
  addres VARCHAR(200)
);

-- [date] take 8 byte.
-- [phonenumber] use number(11)  5 bytes

-- Players Table
CREATE TABLE xPlayers (
    playerID INT,
    EmergencyContact VARCHAR(100),
    ECPhone NUMBER(11) NOT NULL,
    PrefPos CHAR(2)
        CHECK (PrefPos IN ('GK','FB','MF','ST')),
    DomFoot CHAR(1) CHECK (DomFoot IN ('L', 'R')),
    CONSTRAINT xPlayers_PK PRIMARY KEY (playerID),
    CONSTRAINT people_players_FK FOREIGN KEY
        (playerID) REFERENCES xPeople(personID)
);

CREATE TABLE xTeams (
    teamID NUMBER(3) PRIMARY KEY,
    teamName VARCHAR(25) NOT NULL,
    shirtColour VARCHAR(25),
    homefield VARCHAR(40)
    );

CREATE TABLE xRosters (
    teamID NUMBER(3),
    playerID INT,
    shirtNumber NUMBER(3) CHECK(shirtNumber BETWEEN 0 AND 99),
    CONSTRAINT rosters_PK PRIMARY KEY (teamID, playerID),
    CONSTRAINT teams_rosters_FK FOREIGN KEY (teamID)
        REFERENCES xTeams(teamID),
    CONSTRAINT players_rosters_FK FOREIGN KEY (playerID)
        REFERENCES xPlayers(playerID)
    );
    
-- TEMP TABLES
CREATE TABLE xTempEmployees AS 
    SELECT
        employeeNumber,
        firstName || ' ' || lastName AS FullName,
        jobTitle
    FROM employees
    ORDER BY jobTitle, FullName
;
    
-- DROP Tables
DROP TABLE xTempEmployees;

DROP TABLE xTempEmployees CASCADE CONSTRAINTS;
    
-- ALTER
-- add a position column to the roster table
ALTER TABLE xRosters
    ADD pos CHAR(2) CHECK (pos IN ('GK','FB','MF','ST'));
