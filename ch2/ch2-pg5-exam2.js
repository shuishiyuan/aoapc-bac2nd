console.log("The 2nd approach to the 3n+1 Problem");
const lineReader = require("readline");
const cmdLineReader = lineReader.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

let n = 0;
// let n = 0;

cmdLineReader.on('line', (input) => {
    n = parseInt(input);
    console.log(`The input number is: ${n}`);
    let counter = 0;
    while (n > 1) {
        if (n % 2) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        counter++;
    }
    console.log(`${counter} times executed.`);
    cmdLineReader.close();
})