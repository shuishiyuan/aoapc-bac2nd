console.log("Permutation");

let curDigiArr = [];
const consDigits = () => {
    for (let i = 1; i <= 9; ++i) {
        if (curDigiArr.length == 9) {
            console.log(`The digit array is ${curDigiArr}`);
            process.exit()
        }
        if (curDigiArr.indexOf('' + i)) {
            continue;
        }
        consDigits();
    }
}