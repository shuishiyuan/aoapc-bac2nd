console.log("The sum of the factorial");
const { prependOnceListener } = require("process");
const readLine = require("readline");
const cmdLineReader = readLine.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

let n = 0;
let sum = 0;