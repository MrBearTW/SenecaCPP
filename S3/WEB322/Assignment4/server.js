/********************************************************************************
 *  WEB322 – Assignment 03
 *
 *  I declare that this assignment is my own work in accordance with Seneca's
 *  Academic Integrity Policy:
 *
 *  https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
 *
 *  Name: Chi-Wei Perng Student ID: 121967228 Date: 2023-Oct-25
 *
 *  Published URL: https://jade-determined-ostrich.cyclic.app/
 *
 ********************************************************************************/

const path = require("path");
const legoData = require("./modules/legoSets");

const express = require("express");
const app = express();
const HTTP_PORT = process.env.PORT || 8080;

// Add a route handler for the static images and css files
app.use(express.static("public"));

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
  res.sendFile(path.join(__dirname + "/views/home.html"));
});

// About page
app.get("/about", (req, res) => {
  res.sendFile(path.join(__dirname + "/views/about.html"));
});

// Setup a '/lego/sets' route handler that will respond to a request with a list of lego sets
app.get("/lego/sets", (req, res) => {
  if (req.query.theme) {
    legoData
      .getSetsByTheme(req.query.theme)
      .then((data) => {
        res.json(data);
      })
      .catch((err) => {
        res.status(404).json({ message: err });
      });
  } else {
    legoData
      .getAllSets()
      .then((data) => {
        res.json(data);
      })
      .catch((err) => {
        res.status(404).json({ message: err });
      });
  }
});

// Setup a '/lego/sets/num-demo' route handler that will respond to a request with a single lego set
app.get("/lego/sets/:set_num", (req, res) => {
  legoData
    .getSetByNum(req.params.set_num)
    .then((data) => {
      res.json(data);
    })
    .catch((err) => {
      res.status(404).json({ message: err });
    });
});

// 404 with error message
app.use((req, res) => {
  res.status(404).sendFile(path.join(__dirname + "/views/404.html"));
});
