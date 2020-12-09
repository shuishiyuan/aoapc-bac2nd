console.log("Number data statics1 with file readline");
const fs = require("fs");
const { stdout } = require("process");
const lineReader = require("readline");
const fileLineReader = lineReader.createInterface({
    input: fs.createReadStream("data/ch2-pg10-exam5.in"),
    // input: process.stdin,
    output: fs.createWriteStream("data/ch2-pg10-exam5.out")
    // output: process.stdout
});
fileLineReader.on('close', () => {
    process.exit()
});

fileLineReader.on('line', (input) => {
    digit = parseInt(input);
    if (digit === 0) {
        fileLineReader.close()
    }
    console.log(`the input from file is ${digit}`);
});