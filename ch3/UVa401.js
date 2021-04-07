console.log(new Date().toUTCString(), "UVa401 Palindromes in a delegate way");

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});

rl.on('close', () => {
    process.exit();
});

const MIR = 'ABCDEFGHILKJMNOPQR2TUVWXYZ1S3456789';
const MSG = [
    'Neither Symytry Nor Palindrome',
    'Symytry but Not Palindrome',
    'Palindrome but Not Symytry',
    'Both Symytry And Palindrome'
]

const isUpperAlpha = (ch) => {
    let reg = /^[A-Z]+$/;
    return reg.test(ch);
}

const isDigit = (ch) => {
    let reg = /^[0-9]+$/;
    return reg.test(ch);
}

(async () => {
    for await (let line of rl) {
        if ('Q' === line) {
            rl.close();
        }
        let isSymetry = 1;
        let isPalindromes = 1;
        let len = line.length - 1;

        for (let i = 0; i < (1 + len) / 2; ++i) {
            if (line.charAt(i) != line.charAt(len - i)) {
                isSymetry = 0;
                break;
            }
        }

        for (let j = 0; j < (1 + len) / 2; ++j) {
            let mirValue = line.charAt(j);
            if (isUpperAlpha(line.charAt(j))) {
                mirValue = MIR.charAt(line.charAt(j).charCodeAt() - 'A'.charCodeAt());
            }
            if (isDigit(line.charAt(j))) {
                mirValue = MIR.charAt(line.charAt(j).charCodeAt() - '1'.charCodeAt() + 26);
            }
            if (mirValue != line.charAt(len - j)) {
                isPalindromes = 0;
               break;
            }
        }
        console.log(`${line} is ${MSG[2 * isPalindromes + isSymetry]}`);
    }
})();