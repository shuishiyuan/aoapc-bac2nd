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
        let output = '';
        for (let i = 0; i < input.length; ++i) {
            // let c = input(i);
            let c = input.charAt(i);
            let j;
            for (j = 0; DIC.charAt(j) && DIC.charAt(j) != c; ++j);
            if (DIC.charAt(j)) output += DIC.charAt(j - 1);
            else output += c;
        }
        console.log(output);
    };
})();
