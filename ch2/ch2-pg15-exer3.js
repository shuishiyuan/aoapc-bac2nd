console.log("Reverse Triangle");
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});
const justDoIt = async () => {
    let n = 0;
    for await (let input of rl) {
        n = parseInt(input);
        if (n === 0) {
            rl.close();
        }
        if (n > 30) {
            n = 30;
        }
        for (let i = 0; i < n; ++i) {
            let lineStr = '';
            let j = 0;
            while (j < i) {
                lineStr += ' ';
                ++j;
            }
            while (j < 2 * n - 1 - i) {
                lineStr += '*';
                ++j;
            }
            console.log(lineStr);
        }
    }
};
justDoIt();