console.log(new Date().toDateString(), "UVa401 Palindromes");

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

const RAW = '1234567890QWERTYUIOPASDFGHJKLZXCVBNM';
const MIR = '1-E-S67890QWERTYUIOPASDFGHJKLZXCVBNM';

(async () => {
    for await (let line of rl) {
        if ('Q' === line) {
            rl.close();
        };
        let isSymetry = 1;
        let isPalindrome = 1;
    }
})();