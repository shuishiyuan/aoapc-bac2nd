console.log(new Date().toDateString(), 'WERTYU')

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit()
});

const DIC = '1234567890-=!@#$%^&*()_+';

(async () => {
    for await (let line of rl) {
        if (line === 'Q') {
            rl.close();
        }
        let output = '';
        for (let i = 0; i < line.length; ++i) {
            let c = line.charAt(i);
            if (DIC.includes(c)) {
                output += DIC[DIC.indexOf(c) - 1];
            } else {
                output += c;
            }
        }
        console.log(new Date().toUTCString(), output);
    }
});