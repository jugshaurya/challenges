"use strict";

const fs = require("fs");

process.stdin.resume();
process.stdin.setEncoding("utf-8");

let inputString = "";
let currentLine = 0;

process.stdin.on("data", function(inputStdin) {
  inputString += inputStdin;
});

process.stdin.on("end", function() {
  inputString = inputString.split("\n");

  main();
});

function readLine() {
  return inputString[currentLine++];
}
function manipulateStudentRecord(obj, operation, prop, newValue) {
  // write your code here
  if (operation === "delete") {
    let newobj = { ...obj };
    if (newobj.hasOwnProperty(prop)) {
      delete newobj[prop];
    }
    return newobj;
  } else {
    let newobj = { ...obj };
    if (newobj.hasOwnProperty(prop)) {
      return { ...obj, [prop]: newValue };
    }
    return newobj;
  }
}
// function main() {
