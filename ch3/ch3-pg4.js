console.log(`Vertical Form Problem`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});
(async () => {
    for await (let input of rl) {
        if (input === 'Q') {
            rl.close();
        };
        let s = input;
        console.log(`There is no answer to the input: ${s}`);
    };
})();