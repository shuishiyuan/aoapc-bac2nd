console.log(`Opening lights`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit()
});

let printStatus = (lightArr) => {
    let statusArr = [];
    lightArr.array.forEach(element => {
        if (element) {
            statusArr.push(lightArr.indexOf(element));
        }
    });
}

(async () => {
    for await (let input of rl) {
        if (input == 'Q') {
            rl.close();
        }
        let lightArr = [];
        let inputArr = input.trim().split(' ');
        let k = parseInt(inputArr[0]);
        let n = parseInt(inputArr[1]);

        for (let i = 1; i <= k; ++i) {
            for (let j = i; j <= n; j += i) {
                lightArr[j - 1] = !lightArr[j - 1];
            }
            console.log(`The light status after the ${i} th person is: ${lightArr}`);
        }
        printStatus(lightArr);
    }
})();