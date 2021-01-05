console.log("Permutation");

let curDigiArr = '';
// let curDigiArr = [];
const consDigits = () => {
    for (let i = 1; i <= 9; ++i) {
        if (curDigiArr.length == 9) {
            console.log(`The digit array is ${curDigiArr}`);
            process.exit();
        }
        if (curDigiArr.indexOf(i) != -1) {
        // if (curDigiArr.indexOf('' + i)) {
            continue;
        }
        curDigiArr += i;
        // curDigiArr.push('' + i);
        consDigits();
    }
}
consDigits();