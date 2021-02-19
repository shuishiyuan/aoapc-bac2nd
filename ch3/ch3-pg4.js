console.log(`Vertical Form Problem`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});
const paint = (counter, abc, de) => {
    console.log(`<${counter}>`);
    console.log(`  ${abc}`);
    console.log(`X  ${de}`);
    console.log(`-----`);
    console.log(`  ${abc * (de % 10)}`);
    console.log(` ${abc * Math.floor(de / 10)}`);
    console.log(`-----`);
    console.log(` ${abc * de}`);
}

(async () => {
    for await (let input of rl) {
        if (input === 'Q') {
            rl.close();
        };
        let s = input;
        let counter = 0;
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
            console.log(`There is no answer to the input: ${s}`);
        }
    };
})();