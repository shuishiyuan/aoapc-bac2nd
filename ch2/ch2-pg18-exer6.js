console.log("Permutation");

let curDigiArr = [];
// let layerCnt = 0;
const consDigits = () => {
    // layerCnt++;
    for (let i = 1; i <= 9; ++i) {
        if (curDigiArr.length == 9) {
            judgePermutation();
            return;
        }
        if (curDigiArr.indexOf(i) != -1) {
            continue;
        }
        curDigiArr.push(i);
        consDigits();
        // layerCnt--;
        curDigiArr.pop();
    }
}

const judgePermutation = () => {
    const curDigiStr = curDigiArr.join('');
    const a = parseInt(curDigiStr.substr(0, 3));
    const b = parseInt(curDigiStr.substr(3, 3));
    const c = parseInt(curDigiStr.substr(6, 3));
    const aDivideB = (a / b).toFixed(4);
    const bDivideC = (b / c).toFixed(4);
    if (aDivideB == bDivideC) {
        console.log(`The permutation digits are: ${a}\t${b}\t${c}`);
    }
}

console.time("Permutation");
consDigits();
console.timeEnd("Permutation");