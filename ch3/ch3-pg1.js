console.log(`Reversing Input`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

(async () => {
    for await (let input of rl) {
        if (input == 0) {
            rl.close();
        }

        let inputArr = [];
        inputArr = input.trim().split(' ');
        console.log(`The inputs are: ${inputArr}`)

        let outputArr = [];
        while (inputArr.length) {
            outputArr.push(inputArr.pop());
        }
        console.log(`The outputs are: ${outputArr}`)
    }
})();