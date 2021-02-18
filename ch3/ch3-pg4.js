console.log(`Vertical Form Problem`);
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
            rl.close();
        };
        let s = input;
        let counter = 0;
        let vc;
        for(let abc = 111; abc <= 999; ++abc) {
            for (let de = 11; de <= 99; ++de) {
                vc = `${abc * (de % 10)}${abc * de}`;
            }
        }
        console.log(`The last value of abc * de is ${vc}`);
        if (!counter) {
            console.log(`There is no answer to the input: ${s}`);
        }
    };
})();