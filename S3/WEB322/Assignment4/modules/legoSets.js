const setData = require("../data/setData");
const themeData = require("../data/themeData");

let sets = [];

// Put setData into sets after adding theme property = theme.name by themeData theme.id === setData set.theme_id
// If theme.name not found, set.theme = "Unknown"
const Initialize = () => {
  return new Promise((resolve, reject) => {
    try {
      setData.forEach((set) => {
        let theme = themeData.find((theme) => theme.id == set.theme_id);
        if (theme) {
          set.theme = theme.name;
        } else {
          set.theme = "Unknown";
        }
      });
      sets = setData; // Put setData into sets
      resolve();
    } catch (err) {
      reject(err);
    }
  });
};

// •	getAllSets()
// This function simply returns the complete "sets" array
const getAllSets = () => {
  return new Promise((resolve, reject) => {
    if (sets.length === 0) {
      reject("No sets found");
      return;
    }
    resolve(sets);
  });
};

// •	getSetByNum(setNum)
// should resolve with the found "set" object, and reject with an appropriate message
// (ie: unable to find requested set) if the set was not found
const getSetByNum = (setNum) => {
  return new Promise((resolve, reject) => {
    const set = sets.find((set) => set.set_num === setNum);
    if (!set) {
      reject(`No set with number ${setNum}`);
      return;
    }
    resolve(set);
  });
};

// •	getSetsByTheme(theme)
// should resolve with the found "set" objects, and reject with an appropriate message
// (ie: unable to find requested sets)
const getSetsByTheme = (theme) => {
  return new Promise((resolve, reject) => {
    try {
      const filteredSets = sets.filter((set) =>
        set.theme.toLowerCase().includes(theme.toLowerCase())
      );
      if (filteredSets.length === 0) {
        throw `No sets with theme ${theme}`;
      }
      resolve(filteredSets);
    } catch (err) {
      reject(err);
    }
  });
};

module.exports = {
  Initialize,
  getAllSets,
  getSetByNum,
  getSetsByTheme,
};
