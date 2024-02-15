import { useState } from "react";

function getRandomInt(max) {
    return Math.floor(Math.random() * max);
  }

export default function RandomNumbers() {
  const [nums, setNums] = useState([]);

  function generateNumber(e) {
    console.log("Generating number...");
    setNums([...nums, getRandomInt(100)]);
    console.log(nums);
  }

  return (
    <>
      <button onClick={generateNumber}>
        Add Random Number (Check Console)
      </button>
    </>
  );
}
