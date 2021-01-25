console.log(`Snake Matrics`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

let snakArr;

const initiate = (n) => {
    snakArr = [];
    for (let i = 0; i < n; ++i) {
        snakArr[i] = [];
        for (let j = 0; j < n; ++j) {
            snakArr[i][j] = NaN;
        }
    }
}

const goAhead = (n, isVertical) => {
    if (n === 0) {
        return;
    }
    if (isVertical) {
        for (let i = 0; i < n; ++i) {
            snakArr[i][n - 1] = i + 1;
        }

    } else {
        for (let i = 0; i < n; ++i) {
            snakArr[i][n - 1] = i + 1;
        }
    }
    goAhead(n - 1, !isVertical);
}

const printArr = () => {
    let output = '';

    snakArr.forEach(rowElement => {
        rowElement.forEach(colElement => {
            output += colElement + '\t';
        });
        output += '\n';
    });
    console.log(`${output}`);
}

(async () => {
    for await (let input of rl) {
        if (input == 'Q') {
            rl.close();
        }
        let n = parseInt(input);
        initiate(n);
        goAhead(n, true);
        printArr();
    }
})();