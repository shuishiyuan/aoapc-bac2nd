console.log("Number data statics with file readline");
const fs = require("fs");
const lineReader = require("readline");
const fileLineReader = lineReader.createInterface({
    input: fs.createReadStream("data/ch2-pg10-exam5.in"),
    // input: process.stdin,
    output: fs.createWriteStream("data/ch2-pg10-exam5.out")
    // output: process.stdout
});
fileLineReader.on('close', () => {
    console.log(`max:${max}\tmin:${min}\taverage:${(sum / counter).toFixed(2)}\tin ${counter} inputs`)
    process.exit();
});

let sum = 0;
let max = 0;
let min = 0;
let counter = 1;

fileLineReader.on('line', (input) => {
    digit = parseInt(input);
    counter++;
    if (counter === 1) {
        max = min = input;
    }
    if (digit > max) {
        max = digit;
    }
    if (digit < min) {
        min = digit;
    }
    sum += digit;
    // console.log(`the input from file is ${digit}`);
    // console.log(`max:${max}\tmin:${min}\taverage:${(sum / counter).toFixed(2)}`)
    // fileLineReader.prompt(`the input from file is ${digit}`);
});