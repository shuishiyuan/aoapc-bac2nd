console.log(new Date().toUTCString(), "UVa401 Palindromes in a delegate way");

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});

rl.on('close', () => {
    process.exit();
});

const MIR = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789';
const MSG = [
    'Neither Symytry Nor Palindrome',
    'Symytry but Not Palindrome',
    'Palindrome but Not Symytry',
    'Both Symytry And Palindrome'
]

const isUpperAlpha = (ch) => {
    let reg = "^[A-Z]+.?[A-Z]*$";
    return reg.test(ch);
}

const isDigit = (ch) => {
    let reg = "^[0-9]+.?[0-9]*$";
    return reg.test(ch);
}

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
                break;
            }
        }

        for (let j = 0; j < (1 + len) / 2; ++j) {
            let mirValue = line.indexOf(j);
            if (isUpperAlpha(line.indexOf(j))) {
                mirValue = MIR.indexOf(line.indexOf(j).charCodAt() - 'A'.charCodeAt());
            }
            if (isDigit(line.indexOf(j))) {
                mirValue = MIR.indexOf(line.indexOf(j).charCodAt() - '1'.charCodAt() + 26);
            }
            if (mirValue != line.indexOf(len - j)) {
                isPalindromes = false;
               break;
            }
        }
    }
})();