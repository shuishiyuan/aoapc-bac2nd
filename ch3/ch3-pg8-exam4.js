console.log("UVa340 Master-Mind Hints the 1st approach");
// import fs from "fs";
const fs = require("fs");
const rs = fs.createReadStream("data/ch3-pg8-exam4.in");
const ws = fs.createWriteStream("data/ch3-pg8-exam4.out");

let output = '';
let bitWidth = 0;
let demoLine = '';
let gameNo = 0;

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
        let directCnt = 0;
        let extentCnt = 0;
        // output = output + line + '\n';
        if ('0' === line) {
            rl.close();
        }
        if (bitWidth === 0) {
            bitWidth = parseInt(line);
            gameNo++;
            output += 'Game ' + gameNo + ':\n';
            continue;
        }
        if (demoLine === '') {
            demoLine = line;
            continue;
        }
        if (isGameBreak(line)) {
            bitWidth = 0;
            demoLine = '';
            continue;
        }
        for (let i = 0; i < bitWidth; ++i) {
            if (line.includes(demoLine.charAt(i))) {
                if (line.charAt(i) != demoLine.charAt(i)) {
                    extentCnt++;
                } else {
                    directCnt++;
                }
            }
        }
        // extentCnt -= directCnt;
        output += '    (' + directCnt + ',' + extentCnt + ')\n';
    }
})();
