console.log(new Date().toLocaleDateString(), "UVa10082 WERTYU"); 

const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

const DIC = "`1234567890-=!@#$%^&*()_+";

(async () => {
    for await (let input of rl) {
        if (input === 'Q') {
            rl.exit();
        }
        for (let i = 0; i < input.length; ++i) {
            let c = input(i);
        }
    };
})();
