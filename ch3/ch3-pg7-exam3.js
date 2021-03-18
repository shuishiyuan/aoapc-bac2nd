console.log(new Date().toDateString(), "UVa401 Palindromes");

const sprintf = require("sprintf-js").sprintf;
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

const RAW = '1234567890QWERTYUIOPASDFGHJKLZXCVBNM';
const MIR = '1-E-S67890QWERTYUIOPA2DFGHJKLZXCVBNM';
const MSG = [
    "is neither Symetry nor Palindromes.",
    "is Symetry but not Palindromes.",
    "is not Symetry but Palindroes.",
    "is both Symetry and Palindroes."
];

(async () => {
    let output = '';
    for await (let line of rl) {
        if ('Q' === line) {
            console.log(output);
            rl.close();
        };
        let isSymetry = 1;
        let isPalindrome = 1;

        let ascInd = 0;
        let descInd = line.length;
        while (ascInd <= descInd) {
            if (line.charAt(ascInd) != line.charAt(descInd)) {
                isSymetry = 0;
                break;
            }
            ascInd++;
            descInd--;
        }

        ascInd = 0;
        descInd = line.length;
        while (ascInd <= descInd) {
            if (line.charAt(ascInd) != MIR.charAt(RAW.indexOf(line.charAt(descInd)))) {
                isPalindrome = 0;
                break;
            }
            ascInd++;
            descInd--;
        }
        output += sprintf('%s : %s\n', line, MSG[2 * isPalindrome + isSymetry]);
    }
})();