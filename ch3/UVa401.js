console.log(new Date().toUTCString(), "UVa401 Palindromes in a delegate way");

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});

rl.on('close', () => {
    process.exit();
});

const MIR = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789';

(async () => {
    for await (let line of rl) {
        if ('Q' === line) {
            rl.close();
        }
        let isSymetry = true;
        let isPalindromes = true;
        let len = line.length - 1;

        for (let i = 0; i < (1 + len) / 2; ++i) {
            if (line.indexOf(i) != line.indexOf(len - i)) {
                isSymetry = false;
            }
        }
    }
})();