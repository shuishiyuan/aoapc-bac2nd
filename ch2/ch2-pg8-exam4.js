console.log("The sum of the factorial: in a crazy way");
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

let processFactorial = (n) => {
    let factorial = 1;
    for (let i = 1; i <= n; ++i) {
        factorial = (factorial * i) % MOD;
    }
    return factorial;
}

let processSum = (n) => {
    let sum = 0;
    for (let i = 1; i <= n; ++i) {
        sum = (sum + processFactorial(i)) % MOD;
    }
    counter++;
    return sum;
}

cmdLineReader.on('line', (input) => {
    n = parseInt(input);
    if (n === 0) {
        cmdLineReader.close();
    }
    if (n > 24) {
        n = 24;
    }
    let sum = 0;
    console.time('sum-process-time');
    sum = processSum(n);
    console.timeEnd('sum-process-time');
    console.log(`The sum of factorial from 1 to ${n} is: ${sum} in counter: ${counter}`);
});
