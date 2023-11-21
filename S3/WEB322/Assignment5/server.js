/********************************************************************************
 *  WEB322 – Assignment 04
 *
 *  I declare that this assignment is my own work in accordance with Seneca's
 *  Academic Integrity Policy:
 *
 *  https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
 *
 *  Name: Chi-Wei Perng Student ID: 121967228 Date: 2023-Nov-10
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

// Add support for ejs templates
app.set("view engine", "ejs");

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
  res.render("home", { page: "/home" });
});

// About page
app.get("/about", (req, res) => {
  res.render("about", { page: "/about" });
});

app.get("/lego/sets", (req, res) => {
  // console.log(eq.query.theme);
  if (req.query.theme) {
    legoData
      .getSetsByTheme(req.query.theme)
      .then((data) => {
        // res.render("sets", { page: "/sets", data: data, avatar: false });
        res.render("sets", { page: "/sets", data: data});

      })
      .catch((err) => {
        res.status(404).render("404", { page: "/404", message: err });
      });
  } else {
    legoData
      .getAllSets()
      .then((data) => {
        // res.render("sets", { page: "/sets", data: data, avatar: true });
        res.render("sets", { page: "/sets", data: data});

      })
      .catch((err) => {
        res.status(404).render("404", { page: "/404", message: err });
      });
  }
});

app.get("/lego/sets/:set_num", (req, res) => {
  legoData
    .getSetByNum(req.params.set_num)
    .then((data) => {
      res.render("set", { page: "/set", data: data });
    })
    .catch((err) => {
      res.status(404).render("404", { page: "/404", message: err });
    });
});

// 404 with error message
app.use((req, res) => {
  res
    .status(404)
    .render("404", {
      page: "/404",
      message: "I'm sorry, we're unable to find what you're looking for",
    });
});
