/********************************************************************************
 *  WEB322 – Assignment 06
 *
 *  I declare that this assignment is my own work in accordance with Seneca's
 *  Academic Integrity Policy:
 *
 *  https://www.senecacollege.ca/about/policies/academic-integrity-policy.html
 *
 *  Name: Chi-Wei Perng Student ID: 121967228 Date: 2023-DEC-03
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
app.use(express.urlencoded({ extended: true }));

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
  if (req.query.theme) {
    legoData
      .getSetsByTheme(req.query.theme)
      .then((data) => {
        res.render("sets", { page: "/lego/sets", data: data });
      })
      .catch((err) => {
        res.status(404).render("404", { page: "/404", message: err });
      });
  } else {
    legoData
      .getAllSets()
      .then((data) => {
        res.render("sets", { page: "/lego/sets", data: data });
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

// Add a route to go to the addSet page
app.get("/lego/addSet", (req, res) => {
  legoData
    .getAllThemes()
    .then((data) => {
      res.render("addSet", { page: "/lego/addSet", themes: data });
    })
    .catch((err) => {
      res.render("404", { page: "/404", message: err });
    });
});

// Add a route for the POST request to add a new set
app.post("/lego/addSet", (req, res) => {
  legoData
    .addSet(req.body)
    .then(() => {
      console.log("Set Added");
      res.redirect("/lego/sets");
    })
    .catch((err) => {
      res.render("500", {
        message: `I'm sorry, but we have encountered the following error(Post add): ${err}`,
      });
    });
});

// Edit a set
app.get("/lego/editSet/:set_num", (req, res) => {
  Promise.all([
    legoData.getSetByNum(req.params.set_num),
    legoData.getAllThemes(),
  ])
    .then((data) => {
      res.render("editSet", {
        page: "/lego/editSet",
        set: data[0],
        themes: data[1],
      });
    })
    .catch((err) => {
      res.render("404", { page: "/404", message: err });
    });
});

// Add a route for the POST request to edit a set
app.post("/lego/editSet", (req, res) => {
  legoData
    .editSet(req.body.set_num, req.body)
    .then(() => {
      console.log("Set Edited");
      res.redirect("/lego/sets");
    })
    .catch((err) => {
      res.render("500", {
        message: `I'm sorry, but we have encountered the following error(Post edit): ${err}`,
      });
    });
});

// Delete a set
app.get("/lego/deleteSet/:set_num", (req, res) => {
  legoData
    .deleteSet(req.params.set_num)
    .then(() => {
      console.log("Set Deleted");
      res.redirect("/lego/sets");
    })
    .catch((err) => {
      res.render("500", {
        message: `I'm sorry, but we have encountered the following error(Delete): ${err}`,
      });
    });
});

// 500 with error message
app.use((err, req, res, next) => {
  res.render("500", {
    page: "/500",
    message: `I'm sorry, but we have encountered the following error(ALL): ${err}`,
  });
});

// 404 with error message
app.use((req, res) => {
  res.status(404).render("404", {
    page: "/404",
    message: "I'm sorry, we're unable to find what you're looking for",
  });
});
