console.log("Reverse Triangle");
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
const justDoIt = async () => {
    let n = 0;
    for await (let input of rl) {
        n = parseInt(input);
    }
};
justDoIt();