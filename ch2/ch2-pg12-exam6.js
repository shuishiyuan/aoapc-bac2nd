console.log("Number data statics2");
const { count } = require("console");
const { realpath } = require("fs");
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit()
});

let counter = 0;
const processLine = async () => {
    await counter = parseInt(input);
    if (counter === 0 ) {
        rl.close();
    }
}
processLine();