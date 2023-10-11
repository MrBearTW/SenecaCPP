/********************************************************************************
 *  WEB322 – Assignment 02
 *
 *  I declare that this assignment is my own work in accordance with Seneca's
 *  Academic Integrity Policy:
 *
 *  https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
 *
 *  Name: Chi-Wei Perng Student ID: 121967228 Date: 2023-Oct-02
 *
 ********************************************************************************/

const path = require("path");
const legoData = require("./modules/legoSets");

const express = require("express");
const app = express();
const HTTP_PORT = process.env.PORT || 8080;

/*
However, before the server starts (ie: the app.listen() function is invoked), 
we must ensure that the "sets" array has been successfully built within our "legoSets" module.  
Therefore, we must invoke the legoData.initialize() function and 
make sure it has completed successfully (ie "resolves") before we execute our app.listen() function.
*/
legoData
  .Initialize()
  .then(() => {
    console.log("Lego Data Initialized");
  })
  .catch((err) => {
    console.log(err);
  });

app.listen(HTTP_PORT, () => {
  console.log(`Server listening on port ${HTTP_PORT}`);
});

// Setup a 'root' route handler that will respond to a request with the homepage
app.get("/", (req, res) => {
  res.send("Assignment 2: 121967228 - Chi-Wei Perng");
});

// Setup a '/lego/sets' route handler that will respond to a request with a list of lego sets
app.get("/lego/sets", (req, res) => {
  legoData
    .getAllSets()
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.json({ message: err });
    });
});

// Setup a '/lego/sets/num-demo' route handler that will respond to a request with a single lego set
app.get("/lego/sets/num-demo", (req, res) => {
  legoData
    .getSetByNum("071-1") // Temp hardcode
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.json({ message: err });
    });
});

// Setup a '/lego/sets/theme-demo' route handler that will respond to a request with a list of lego sets
app.get("/lego/sets/theme-demo", (req, res) => {
  legoData
    .getSetsByTheme("Basic Set") // Temp hardcode
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.json({ message: err });
    });
});
