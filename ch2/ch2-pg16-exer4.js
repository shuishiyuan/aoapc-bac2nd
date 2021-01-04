console.log("Subsequence");
const { readlink } = require("fs");
const readLine = require("readline");
const rl = readLine.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit()
});

let counter = 1;
let n  = 0;
let m = 0;
const processLine = async () => {
    for await (let input of rl) {
        if (input == 0) {
            rl.close();
        }
        if (counter === 1) {
            n = parseInt(input);
            counter++;
            continue;
        }
        m = parseInt(input);
        let sum = 0;
        for (let i = n; i <= m; ++i) {
            sum += 1 / Math.pow(i, 2);
        }
        console.log(`The Subsequence value of ${n} and ${m} is: ${sum.tofixed(5)}`);
        counter = 1;
    }
}
processLine();