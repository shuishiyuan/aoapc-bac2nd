console.log("The sum of the factorial: in recursion");
const lineReader = require("readline");
const cmdLineReader = lineReader.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

let n = 0;

let processFractional = (n) => {
    if (n === 1) {
        return 1;
    }
    return n * processFractional(n - 1);
}
 let processSum = (n) => {
     if (n === 1) {
         return 1;
     }
     return processFractional(n) + processSum(n - 1);
 }

cmdLineReader.on('line', (input) => {
    n = parseInt(input);
    if (n === 0) {
        cmdLineReader.close();
    }
    const sum = processSum(n);
    // for (let i = 1; i <= n; i++) {
        // sum += processFractional(i);
    // }
    console.log(`The sum of the fractional from 1 to ${n} is :${sum}`);
})