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
    /* lightArr.forEach((element, idx) => {
        if (element) {
            statusArr.push(idx);
        }
    }); */
    /* for (idx in lightArr) {
        if (lightArr[idx]) {
            statusArr.push(idx);
        }
    } */
    for (let item of lightArr) {
        if (item) {
            statusArr.push(lightArr.toString().indexOf(item));
        }
    }
    console.log(`The Current Status of light is: ${statusArr}`);
}

(async () => {
    for await (let input of rl) {
        if (input == 'Q') {
            rl.close();
        }
        let lightArr = [];
        let inputArr = input.trim().split('\t');
        let k = parseInt(inputArr[0]);
        let n = parseInt(inputArr[1]);

        for (let i = 1; i <= k; ++i) {
            for (let j = i; j <= n; j += i) {
                lightArr[j] = !lightArr[j];
            }
            // console.log(`The light status after the ${i} th person is: ${lightArr}`);
            printStatus(lightArr);
        }
        // printStatus(lightArr);
    }
})();