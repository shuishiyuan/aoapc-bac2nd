console.log(`Snake Matrics`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

let snakArr;

const goAhead = (n) => {
    for (let i = 0; i < n; ++i) {
        snakArr[i][n - 1] = i + 1;
    }
}

const printArr = () => {
    let output = '';

    snakArr.forEach(rowElement => {
        rowElement.forEach(colElement => {
            output += colElement + '\t';
        });
        output += '\n';
    });
}

(async () => {
    for await (let input of rl) {
        if (input == 'Q') {
            rl.close();
        }
        let n = parseInt(input);
        snakArr = [[]];
        goAhead(n);
        printArr();
    }
})();