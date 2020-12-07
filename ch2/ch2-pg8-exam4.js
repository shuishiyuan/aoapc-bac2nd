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
let sum = 0;

let processFactorial = (n) => {
    let factorial = 1;
    for (let i = 1; i <= n; ++i) {
        factorial = factorial * i;
    }
    return factorial;
}

let processSum = (n) => {
    sum = 0;
    for (let i = 1; i <= n; ++i) {
        sum = sum + processFactorial(i);
    }
}

cmdLineReader.on('line', (input) => {
    if (input === 0) {
        cmdLineReader.close();
    }
    n = input;
    console.time('sum-process-time');
    sum = processSum(n);
    console.timeLog('sum-process-time', sum);
    console.log(`The sum of factorial from 1 to ${n} is: ${sum}`);
});
