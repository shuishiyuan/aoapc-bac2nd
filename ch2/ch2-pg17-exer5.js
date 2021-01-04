console.log("Decimal");
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});
let counter = 1;
let a, b, c;
(async () => {
    for await (let input of rl) {
        if (input == 0) {
            rl.close();
        }
        if (counter === 1) {
            a = parseInt(input);
            counter++;
            continue;
        }
        if (counter === 2) {
            b = parseInt(input);
            counter++
            continue;
        }
        c = parseInt(input);
        console.log(`The ${c} decimal digits result of ${a} / ${b} is: ${(a / b).toFixed(c)}`);
        counter = 1;
    }
})();