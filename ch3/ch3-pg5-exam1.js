console.log(new Date().toLocaleString(), "UVa272 Tex Quotes\n");
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

(async () => {
    for  await (let input of rl) {
        if (input === 'Q') {
            rl.close();
        }
        for (let i = 0; i < input.lentgh; ++i) {
            let c = input.charAtIndex(i);
            let quoting = false;
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
        console.log(new Date().toUTCString(), s);
    }
})();