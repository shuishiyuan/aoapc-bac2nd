console.log(new Date().toUTCString(), 'UVa272 text quotes elegant way');

const readline = require("readline");
const { rootCertificates } = require("tls");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

(async () => {
    for await (let input of rl) {
        if (input === 'Q') {
            console.log(new Date().toUTCString(), 'See You~~~~');
            rl.close();
        }
        let s = '';
        let q = false;
        for (let i = 0; i < input.length; ++i) {
            let c = input.charAt(i);
            if (c === '\"') {
                s += !q ? '``' : '\'\'';
                q = !q;
            } else {
                s += c;
            }
        }
        console.log(s);
    };
})();