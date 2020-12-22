console.log("Number data statics2");
const workspaceFolder = 'D:/MINE/workspace/aoapc-bac2nd'
const fs = require("fs");
const readline = require("readline");
const rl = readline.createInterface({
    input: fs.createReadStream(`${workspaceFolder}/ch2/data/ch2-pg12-exam6.in`)
});
rl.on('close', () => {
    process.exit()
});

let counter = undefined;
let sum = 0;
let max = Number.MIN_SAFE_INTEGER;
let min = Number.MAX_SAFE_INTEGER;
let index = 0;
const processLine = async () => {
    for await (const input of rl) {
        if (input == 0) {
            rl.close();
        } else if (counter === undefined) {
            counter = parseInt(input);
            sum = 0;
            max = Number.MIN_SAFE_INTEGER;
            min = Number.MAX_SAFE_INTEGER;
            index = counter;
        } else if (index > 0) {
            let digit = parseInt(input);
            sum += digit;
            if (digit > max) {
                max = digit;
            }
            if (digit < min) {
                min = digit;
            }
            index--;
            if (index === 0) {
                console.log(`counter: ${counter}\tmax: ${max}\tmin: ${min}\taverage: ${(sum / counter).toFixed(3)}`);
                counter = undefined;
            }
        }
    }
}
processLine();