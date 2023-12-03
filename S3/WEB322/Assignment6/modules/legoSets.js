// Insert data into database ===================================================
// const setData = require("../data/setData");
// const themeData = require("../data/themeData");
// let sets = [];
// Insert data into database ===================================================

require("dotenv").config();
const Sequelize = require("sequelize");

// Create the "sequelize" object using the Sequelize() constructor
let sequelize = new Sequelize(
  process.env.DB_DATABASE,
  process.env.DB_USER,
  process.env.DB_PASSWORD,
  {
    host: process.env.DB_HOST,
    dialect: "postgres",
    port: 5432,
    dialectOptions: {
      ssl: {
        rejectUnauthorized: false,
      },
    },
  }
);

// Test connection to database
// sequelize
//   .authenticate()
//   .then(() => {
//     console.log("Connection has been established successfully.");
//   })
//   .catch((err) => {
//     console.log("Unable to connect to the database:", err);
//   });

// Define the "Theme" model
const Theme = sequelize.define(
  "Theme",
  {
    id: {
      type: Sequelize.INTEGER,
      primaryKey: true,
      autoIncrement: true,
    },
    name: Sequelize.STRING,
  },
  {
    createdAt: false, // disable createdAt
    updatedAt: false, // disable updatedAt
  }
);

// Define the "Set" model
const Set = sequelize.define(
  "Set",
  {
    set_num: {
      type: Sequelize.STRING,
      primaryKey: true,
    },
    name: Sequelize.STRING,
    year: Sequelize.INTEGER,
    num_parts: Sequelize.INTEGER,
    theme_id: Sequelize.INTEGER,
    img_url: Sequelize.STRING,
  },
  {
    createdAt: false, // disable createdAt
    updatedAt: false, // disable updatedAt
  }
);

// Create an association between the two models
Set.belongsTo(Theme, {
  foreignKey: "theme_id",
});

// Initialize ========================================================================
const Initialize = () => {
  return new Promise((resolve, reject) => {
    sequelize
      .sync()
      .then(() => {
        console.log("Connection to database successful");
        resolve();
      })
      .catch((err) => {
        console.log("Unable to connect to the database:", err);
        reject(err);
      });
  });
};

// getAllSets() ======================================================================
const getAllSets = () => {
  return new Promise((resolve, reject) => {
    Set.findAll({
      include: [Theme],
    })
      .then((sets) => {
        resolve(sets);
      })
      .catch((err) => {
        reject(err);
      });
  });
};

// getSetByNum(setNum) ===============================================================
const getSetByNum = (setNum) => {
  return new Promise((resolve, reject) => {
    Set.findAll({
      include: [Theme],
      where: {
        set_num: setNum,
      },
    })
      .then((sets) => {
        if (sets.length === 0) {
          reject(`Unable to find requested set: ${setNum}`);
        }
        resolve(sets[0]);
      })
      .catch((err) => {
        reject(err);
      });
  });
};

// getSetsByTheme(theme) =============================================================
const getSetsByTheme = (theme) => {
  return new Promise((resolve, reject) => {
    Theme.findAll({
      where: {
        name: {
          [Sequelize.Op.iLike]: `%${theme}%`,
        },
      },
    })
      .then((themes) => {
        if (themes.length === 0) {
          reject(`Unable to find requested sets ${theme}`);
        }
        Set.findAll({
          include: [Theme],
          where: {
            theme_id: themes[0].id,
          },
        })
          .then((sets) => {
            resolve(sets);
          })
          .catch((err) => {
            reject(err);
          });
      })
      .catch((err) => {
        reject(err);
      });
  });
};

// getAllThemes ==========================================================================
const getAllThemes = () => {
  return new Promise((resolve, reject) => {
    Theme.findAll()
      .then((themes) => {
        resolve(themes);
      })
      .catch((err) => {
        reject(err);
      });
  });
};

// add(setData) ==========================================================================
const addSet = (setData) => {
  return new Promise((resolve, reject) => {
    Set.create(setData)
      .then(() => {
        resolve();
      })
      .catch((err) => {
        reject(err.errors[0].message);
      });
  });
};

// editSet(set_num, setData) ===============================================================
const editSet = (set_num, setData) => {
  return new Promise((resolve, reject) => {
    Set.update(setData, {
      where: {
        set_num: set_num,
      },
    })
      .then(() => {
        resolve();
      })
      .catch((err) => {
        reject(errerr.errors[0].message);
      });
  });
};

// deleteSet(set_num) ======================================================================
const deleteSet = (set_num) => {
  return new Promise((resolve, reject) => {
    Set.destroy({
      where: {
        set_num: set_num,
      },
    })
      .then(() => {
        resolve();
      })
      .catch((err) => {
        reject(err.errors[0].message);
      });
  });
};

module.exports = {
  Initialize,
  getAllSets,
  getSetByNum,
  getSetsByTheme,
  addSet,
  getAllThemes,
  editSet,
  deleteSet,
};

// Insert data into database ===============================================================
// // Adding Existing Lego Sets using "BulkCreate"
// // node modules/legoSets.js

// sequelize
//   .sync()
//   .then( async () => {
//     try{
//       await Theme.bulkCreate(themeData);
//       await Set.bulkCreate(setData);
//       console.log("-----");
//       console.log("data inserted successfully");
//     }catch(err){
//       console.log("-----");
//       console.log(err.message);

//       // NOTE: If you receive the error:

//       // insert or update on table "Sets" violates foreign key constraint "Sets_theme_id_fkey"

//       // it is because you have a "set" in your collection that has a "theme_id" that does not exist in the "themeData".

//       // To fix this, use PgAdmin to delete the newly created "Themes" and "Sets" tables, fix the error in your .json files and re-run this code
//     }

//     process.exit();
//   })
//   .catch((err) => {
//     console.log('Unable to connect to the database:', err);
//   });
// Insert data into database ===============================================================
