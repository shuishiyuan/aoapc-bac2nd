console.log("The sum of the factorial: in loop");
const readLine = require("readline");
const cmdLineReader = readLine.createInterface({
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
    for (let i = 1; i <= n; i++) {
        let factorial = 1;
        for (j = 1; j <= i; j++) {
            factorial *= j;
        }
        sum += factorial;
    }
    console.log(`The sum of factorial from 1 to ${n} is: ${sum}`);
})