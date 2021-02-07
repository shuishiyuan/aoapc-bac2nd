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
    for (let i = 0; i <= n; ++i) {
        snakArr[i] = [];
        for (let j = 0; j <= n; ++j) {
            snakArr[i][j] = 'WALL';
        }
    }
}

const goAhead = (n, direction) => {
    if (snakArr[curRow][curCol] !== 'WALL') {
        return;
    }
    if (direction % 4 === 1) {
         while (snakArr[curRow + 1][curCol] === 'WALL') {
            snakArr[curRow++][curCol] = curDgt++;
            if (curRow === n - 1) {
                break;
            }
        }
        snakArr[curRow][curCol] = curDgt++;
        curCol--;
    } else if (direction % 4 === 2) {
        while (curCol >= 0) {
            snakArr[curRow][curCol] = curDgt++;
            if (curCol === 0) {
                curRow--;
                break;
            }
            if (snakArr[curRow][curCol - 1] !== 'WALL') {
                curRow--;
                break;
            }
            curCol--;
        }
    } else if (direction % 4 === 3) {
        while (curRow >= 0) {
            snakArr[curRow][curCol] = curDgt++;
            if (curRow === 0) {
                curCol++;
                break;
            }
            if (snakArr[curRow - 1][curCol] !== 'WALL') {
                curCol++;
                break;
            }
            curRow--;
        }
    } else {
        while (curCol < n) {
            snakArr[curRow][curCol] = curDgt++;
            if (curCol === n - 1) {
                curRow++;
                break;
            }
            if (snakArr[curRow][curCol + 1] !== 'WALL') {
                curRow++;
                break;
            }
            curCol++;
        }
        // n--;
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
        curRow = 0;
        curCol = n - 1;
        curDgt = 1;
        goAhead(n, 1);
        printArr();
    }
})();