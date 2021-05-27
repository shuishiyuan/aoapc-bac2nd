console.log("UVa340 Master-Mind Hints the 1st approach");
const fs = require("fs");
const rs = fs.createReadStream("data/ch3-pg8-exam4.in");
const ws = fs.createWriteStream("data/ch3-pg8-exam4.out");

const readline = require("readline");
const rl = readline.createInterface({
    input: rs
});
rl.on('close', () => {
    process.exit();
});

(async () => {
    for await (let line of rl) {
        if ('0' === line) {
            rl.close();
        }
        ws.write(line);
        console.log(line);
    }
})();
