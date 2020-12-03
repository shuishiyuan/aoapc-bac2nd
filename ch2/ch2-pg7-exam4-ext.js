console.log("The sum of the factorial: in recursion");
const lineReader = require("readline");
const cmdLineReader = lineReader.createInterface({
    input: process.stdin
});
cmdLineReader.on('close', () => {
    process.exit()
});

const MOD = 1000000;
let n = 0;
let counter = 1;

let processFractional = (n) => {
    if (n === 1) {
        return 1;
    }
    return n * processFractional(n - 1) % MOD;
}

let processSum = (n) => {
    if (n === 1) {
        return 1;
    }
    return processFractional(n) + processSum(n - 1);
}

console.time('fractional-process-time');
cmdLineReader.on('line', (input) => {
    n = parseInt(input);
    if (n === 0) {
        cmdLineReader.close();
    }
    // const sum = processFractional(n) % MOD;
    const sum = processSum(n);
    console.log(`The sum of the fractional from 1 to ${n} is :${sum}`);
    console.timeLog('fractional-process-time', sum);
    counter++
})