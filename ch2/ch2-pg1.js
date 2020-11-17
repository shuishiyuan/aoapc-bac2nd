console.log("Print the value of 1,2,3,...,n");
const lineReader = require("readline");
const cmdLineReader = lineReader.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

let n;

cmdLineReader.on('line', (input) => {
    n = parseInt(input);
    console.log(`The input value is: ${n}`);
    for (let i = 1; i <= n; ++i) {
        console.log(`${i}`);
    }
    cmdLineReader.close();
});