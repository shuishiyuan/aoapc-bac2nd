console.log("Permutation");

let curDigiArr = '';
let layerCnt = 0;
// let curDigiArr = [];
const isPermutation = () => {
    let rtnValue = false;
    const a = parseInt(curDigiArr.substr(0, 3));
    const b = parseInt(curDigiArr.substr(3, 3));
    const c = parseInt(curDigiArr.substr(6, 3));
    const aDivideB = (a / b).toFixed(5);
    const bDivideC = (b / c).toFixed(5);
    if (aDivideB == bDivideC) {
        rtnValue = true;
    }
    return rtnValue;
}

const consDigits = () => {
    layerCnt++;
    for (let i = 1; i <= 9; ++i) {
        if (curDigiArr.length == 9) {
            if (isPermutation()) {
                console.log(`The digit array is ${curDigiArr}`);
            }
            // curDigiArr = '';
            return;
            // process.exit();
        }
        if (curDigiArr.indexOf(i) != -1) {
            // if (curDigiArr.indexOf('' + i)) {
            continue;
        }
        curDigiArr += i;
        // curDigiArr.push('' + i);
        consDigits();
        layerCnt--;
        curDigiArr = curDigiArr.substr(0, curDigiArr.length - 1);
        if (layerCnt == 1) {
            curDigiArr = '';
        }
    }
}
consDigits();