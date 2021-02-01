console.log(`Snake Matrics`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

let snakArr;
let curDgt = 1;

const initiate = (n) => {
    snakArr = [];
    for (let i = 0; i < n; ++i) {
        snakArr[i] = [];
        for (let j = 0; j < n; ++j) {
            snakArr[i][j] = NaN;
        }
    }
}

const goAhead = (n, direction) => {
    if (n === 0) {
        return;
    }
    if (direction % 4 === 1) {
        for (let i = 0; i < n; ++i) {
            snakArr[i][n - 1] = curDgt++;
        }
    } else if (direction % 4 === 2) {
        for (let i = n - 1; i >= 0; --i) {
            snakArr[n][i] = curDgt++;
        }
    } else if (direction % 4 === 3) {
        for (let i = 0; i < n; ++i) {
            snakArr[i][n - 1] = i + 1;
        }
    } else {
        for (let i = 0; i < n; ++i) {
            snakArr[i][n - 1] = i + 1;
        }
    }
    goAhead(n - 1, !direction);
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
        goAhead(n, 1);
        printArr();
    }
})();