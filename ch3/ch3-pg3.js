console.log(`Snake Matrics`);
const readline = require("readline");
const rl = readline.createInterface({
    input: process.stdin
});
rl.on('close', () => {
    process.exit();
});

let snakArr;
let curDgt;
let curRow;
let curCol;

const initiate = (n) => {
    snakArr = [];
    for (let i = 0; i <= n + 1; ++i) {
        snakArr[i] = [];
        for (let j = 0; j <= n + 1; ++j) {
            snakArr[i][j] = 'WALL';
        }
    }
}

const goAhead = (n, direction) => {
    if (snakArr[curRow][curCol] !== 'WALL') {
        return;
    }
    if (direction % 4 === 1) {
        while (snakArr[curRow + 1][curCol] === 'WALL' && curRow != n) {
            snakArr[curRow++][curCol] = curDgt++;
        }
        snakArr[curRow][curCol] = curDgt++;
        curCol--;
    } else if (direction % 4 === 2) {
        while (snakArr[curRow][curCol - 1] === 'WALL' && curCol != 1) {
            snakArr[curRow][curCol--] = curDgt++;
        }
        snakArr[curRow][curCol] = curDgt++;
        curRow--;
    } else if (direction % 4 === 3) {
        while (snakArr[curRow - 1][curCol] === 'WALL' && curRow != 1) {
            snakArr[curRow--][curCol] = curDgt++;
        }
        snakArr[curRow][curCol] = curDgt++;
        curCol++;
    } else {
        while (snakArr[curRow][curCol + 1] === 'WALL' && curCol != n) {
            snakArr[curRow][curCol++] = curDgt++;
        }
        snakArr[curRow][curCol] = curDgt++;
        curRow++;
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
        curRow = 1;
        curCol = n;
        curDgt = 1;
        goAhead(n, 1);
        printArr();
    }
})();