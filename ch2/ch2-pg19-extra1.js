console.log("Print the value of 2,4,6,...,2n");

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

let n;

(async () => {
    for await (let input of rl) {
        n = parseInt(input);
        if (n === 0) {
            rl.close();
        }
        console.log('');
        for (let i = 1; i <= n; ++i) {
            console.log(`${2 * i}`);
        }
    }
})();