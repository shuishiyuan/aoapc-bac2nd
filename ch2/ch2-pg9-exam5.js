console.log("Number data statics1 with cmd readline");
const lineReader = require("readline");
const cmdLineReader = lineReader.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

let counter = 0;
let max = 0;
let min = 0;
let sum = 0;

cmdLineReader.on('line', (input) => {
    let number = parseInt(input);
    if (number == 0) {
        console.log(`number: ${counter}\tmax: ${max}\tmin: ${min}\taverage: ${(sum / counter).toFixed(2)}`)
        cmdLineReader.close();
    }
    counter++
    if (counter == 1) {
        max = min = number;
    }
    if (number > max) {
        max = number;
    }
    if (number < min) {
        min = number;
    }
    sum += number;
});