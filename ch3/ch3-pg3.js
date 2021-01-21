console.log(`Snake Matrics`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

const goAhead = () => {
    ;
}

(async () => {
    for await (let input of rl) {
        if (input == 'Q') {
            rl.close();
        }
    }
})