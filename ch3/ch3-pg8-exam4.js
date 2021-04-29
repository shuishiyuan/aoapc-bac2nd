console.log("UVa340 Master-Mind Hints the 1st approach");
const fs = require("fs");

const readline = require("readline");
const rl = readline.createInterface({
    input: fs.read("data/ch3-pg8-exam4.in")
});
rl.on('close', () => {
    process.exit();
});

(async () => {
    for await (line of rl) {
        if (line === 0){
            rl.close();
        }
    }
})();
