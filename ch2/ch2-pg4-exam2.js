console.log("The 3n+1 Problem");
const lineRdr = require("readline");
const cmdLineRdr = lineRdr.createInterface({
    input: process.stdin
});
cmdLineRdr.on('close', () => {
    process.exit();
});

let n = 0;

cmdLineRdr.on('line', (input) => {
    n = parseInt(input);
    console.log(`The input number is: ${n}`);
    cmdLineRdr.close();
});
