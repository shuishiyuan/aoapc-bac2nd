console.log(new Date().toLocaleString(), "UVa272 Tex Quotes\n");
const { EOF } = require("dns");
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

(async () => {
    for await (let input of rl) {
        if (input === 'Q') {
            console.log(new Date().toUTCString(), 'See You~~~');
            rl.close();
        }
        let s = '';
        let quoting = false;
        for (let i = 0; i < input.length; ++i) {
            let c = input.charAt(i);
            if (c === '\"') {
                if (!quoting) {
                    s += '``';
                    quoting = true;
                } else {
                    s += '\'\''
                    quoting = false;
                }
            } else {
                s += c;
            }
        }
        console.log(s);
    }
})();