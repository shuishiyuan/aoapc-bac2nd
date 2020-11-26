console.log("The sum of the factorial: in recursion");
const lineReader = require("readline");
const cmdLineReader = lineReader.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

let n = 0;

cmdLineReader.on('line', (input) => {
    n = parseInt(input);
    if (n === 0) {
        cmdLineReader.close();
    }
    let sum = 0;
    console.log(`The sum of the fractional from 1 to ${n} is :${sum}`);
})