console.log("UVa340 Master-Mind Hints the 1st approach");
const fs = require("fs");
const rs = fs.createReadStream("data/ch3-pg8-exam4.in");
const ws = fs.createWriteStream("data/ch3-pg8-exam4.out");

let output = '';

const readline = require("readline");
const rl = readline.createInterface({
    input: rs
});
rl.on('close', () => {
    ws.write(output);
    process.exit();
});


(async () => {
    for await (let line of rl) {
        console.log(line);
        output = output + line + '\n';
        if ('0' === line) {
            rl.close();
        }
    }
})();
