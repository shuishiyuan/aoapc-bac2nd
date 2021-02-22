const util = require("util");
util.log(`Vertical Form Problem`);
util.debuglog(`Vertical Form Problem`);
const sprintf = require('sprintf-js').sprintf;
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});
const paint = (counter, abc, de) => {
    let output = util.format('<%d>\n', counter);
    // output += util.format('%s%d\n', '', abc);
    output += sprintf('%5d\n', abc);
    output += sprintf('X%4d\n', de);
    output += sprintf(`-----\n`);
    output += sprintf('%5d\n', `${abc * (de % 10)}`);
    output += sprintf('%4d\n', `${abc * Math.floor(de / 10)}`);
    output += sprintf(`-----\n`);
    output += sprintf('%5d\n', `${abc * de}`);
    console.log(output);
}

(async () => {
    for await (let input of rl) {
        if (input === 'Q') {
            rl.close();
        };
        let s = input;
        let counter = 0;
        paint(counter, 999, 99);
        let vc;
        for (let abc = 111; abc <= 999; ++abc) {
            for (let de = 11; de <= 99; ++de) {
                vc = `${abc}${de}${abc * (de % 10)}${abc * Math.floor(de / 10)}${abc * de}`;
                let result = true;
                for (let i = 0; i < vc.length; ++i) {
                    c = vc.charAt(i);
                    if (!s.includes(c)) {
                        result = false;
                        break;
                    }
                }
                if (result) {
                    paint(++counter, abc, de);
                }
            }
        }
        if (!counter) {
            // console.log(`There is no answer to the input: ${s}`);
            // console.timeStamp(`There is no answer to the input: `);
            // console.timeStamp(`There is no answer to the input: ${s}`);
            util.log(`There is no answer to the input: ${s}`);
        }
    };
})();