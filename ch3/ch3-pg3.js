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
let curRow = 0;
let curCol = 0;

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
        while (curRow < n) {
            snakArr[curRow][curCol] = curDgt++;
            if (curRow == n - 1) {
                break;
            }
            if (snakArr[curRow + 1][curCol] != NaN) {
                curCol--;
                break;
            }
            curRow++
        }
    } else if (direction % 4 === 2) {
        for (let i = n - 1; i >= 0; --i) {
            snakArr[curRow][i] = curDgt++;
        }
    } else if (direction % 4 === 3) {
        for (let i = 0; i < n; ++i) {
            snakArr[i][n - 1] = i + 1;
        }
    } else {
        for (let i = 0; i < n; ++i) {
            snakArr[i][n - 1] = i + 1;
        }
        n--;
    }
    goAhead(n, ++direction);
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
        curCol = n - 1;
        goAhead(n, 1);
        printArr();
    }
})();