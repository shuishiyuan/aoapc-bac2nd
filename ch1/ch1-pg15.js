console.log("Leasure Time Program");
const lineReader = require("readline");
const cmdLineReader = lineReader.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

let a;
let b;
let counter = 1;

cmdLineReader.on('line', (input) => {
    if (counter === 1) {
        a = input;
    }
    if (counter === 2) {
        b = input;
        console.log("The input sequence is:", `\n${a}\n\n${b}`);
        cmdLineReader.close();
    }
    counter++;
})