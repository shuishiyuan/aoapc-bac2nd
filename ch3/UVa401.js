console.log(new Date().toUTCString(), "UVa401 Palindromes in a delegate way");

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});

rl.on('close', () => {
    process.exit();
});

const MIR = 'A---3--HIL-JM-O---2TUVWXY51SE-Z--8-';
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

        console.time('loop-metrix');
        for (let i = 0; i < (1 + len) / 2; ++i) {
            let c = line.charAt(i);
            if (isSymetry) {
                if (c != line.charAt(len - i)) {
                    isSymetry = 0;
                }
            }
            if (isPalindromes) {
                if (isUpperAlpha(c)) {
                    c = MIR.charAt(c.charCodeAt() - 'A'.charCodeAt());
                }
                if (isDigit(c)) {
                    c = MIR.charAt(c.charCodeAt() - '1'.charCodeAt() + 26);
                }
                if (c != line.charAt(len - i)) {
                    isPalindromes = 0;
                }
            }
            if (!isPalindromes && !isSymetry) {
                break;
            }
        }
        console.log(`${line} is ${MSG[2 * isPalindromes + isSymetry]}`);
        console.timeEnd('loop-metrix');
    }
})();