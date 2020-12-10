console.log("Number data statics with file readline");
const fs = require("fs");
const os = require("os");
const lineReader = require("readline");
const fileReader = fs.createReadStream("data/ch2-pg10-exam5.in");
const lineFileReader = lineReader.createInterface({
    input: fileReader
});
const fileWriter = fs.createWriteStream("data/ch2-pg10-exam5.out");

lineFileReader.on('close', () => {
    console.log(`max:${max}\tmin:${min}\taverage:${(sum / counter).toFixed(2)}\tin ${counter} inputs`);
    fileWriter.write(`max:${max}\tmin:${min}\taverage:${(sum / counter).toFixed(2)}\tin ${counter} inputs${os.EOL}`);
    process.exit();
});

let sum = 0;
let max = 0;
let min = 0;
let counter = 0;

lineFileReader.on('line', (input) => {
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
});