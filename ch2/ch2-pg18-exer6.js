console.log("Permutation");

let curDigiArr = '';
// let curDigiArr = [];
const isPermutation = () => {
    let rtnValue = false;
    const a = parseInt(curDigiArr.substr(0, 3));
    const b = parseInt(curDigiArr.substr(3, 3));
    const c = parseInt(curDigiArr.substr(6, 3));
    if (b * b == a * c) {
        rtnValue = true;
    }
    return rtnValue;
}

const consDigits = () => {
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
        curDigiArr = '';
    }
}
consDigits();