console.log("UVa340 Master-Mind Hints the 1st approach");
const fs = require("fs");
const rs = fs.createReadStream("data/ch3-pg8-exam4.in");
const ws = fs.createWriteStream("data/ch3-pg8-exam4.out");

let output = '';
let bitWidth = 0;

const readline = require("readline");
const rl = readline.createInterface({
    input: rs
});
rl.on('close', () => {
    ws.write(output);
    process.exit();
});

const isGameBreak = (line) => {
    let cnt = bitWidth;
    while (--cnt >= 0) {
        if (line.charAt(cnt) != '0') {
            return false;
        }
    }
    return true;
}

(async () => {
    for await (let line of rl) {
        console.log(line);
        output = output + line + '\n';
        if ('0' === line) {
            rl.close();
        }
        if (bitWidth === 0) {
            bitWidth = parseInt(line);
            continue;
        }
        if (isGameBreak(line)) {
            bitWidth = 0;
            continue;
        }
    }
})();
