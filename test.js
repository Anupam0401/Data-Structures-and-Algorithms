"use strict";

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", (inputStdin) => {
  inputString += inputStdin;
});

process.stdin.on("end", (_) => {
  inputString = inputString
    .trim()
    .split("\n")
    .map((str) => str.trim());

  main();
});

function readLine() {
  return inputString[currentLine++];
}

function main() {
  // objectKey
  let objectKey = readLine();
  // val
  let val = JSON.parse(readLine().replace(/'/g, '"'));
  // cat
  let cat = {
    name: "lizzie",
    age: 18,
    "fur color": "grey",
    likes: ["catnip", "milk"],
    birthday: { month: 7, day: 17, year: 1994 }
  };

  /*
   * Write your code here and log the output.
   */
  //  update the  value of the object with the key objectKey to val
  cat[objectKey] = val;
  console.log(cat);
    
}


