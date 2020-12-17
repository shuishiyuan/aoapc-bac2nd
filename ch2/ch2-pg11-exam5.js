console.log("Number data statics with async await");
const os = require("os");
const fs = require("fs");

const rs = fs.createReadStream("data/ch2-pg11-exam5.in");
const ws = fs.createWriteStream("data/ch2-pg11-exam5.out");

const rl = require("readline");
const { once } = require("events");

let digit = 0;
let sum = 0;
let counter = 0;
let max = 9 << 2;
// let max = (-1) >> 1;
// let max = 0x8000000000000000;
let min = (~ 0) >> 1;
// let min = max + 1;
// let min = 0x7fffffffffffffff;
console.log(`max: ${max}\tmin: ${min}`);

const frl = rl.createInterface({
    input: rs
});

frl.on('close', () => {
    console.log(`Counter:${counter}\tAverage:${(sum / counter).toFixed(3)}\tMax:${max}\tMin:${min}`);
    ws.write(`Counter:${counter}\tAverage:${(sum / counter).toFixed(3)}\tMax:${max}\tMin:${min}${os.EOL}`);
    process.exit();
});

const processLine =  async () => {
    for await (const input of frl) {
        counter++;
        digit = parseInt(input);
        sum += digit;
        if (digit > max) {
            max = digit;
        }
        if (digit < min) {
            min = digit;
        }
    }
    // await once(frl, 'close');
    // await once('beforeExit', () => {
    /* once('beforeExit', () => {
        console.log(`Counter:${counter}\tAverage:${(sum / counter).toFixed(3)}\tMax:${max}\tMin:${min}`);
        ws.write(`Counter:${counter}\tAverage:${(sum / counter).toFixed(3)}\tMax:${max}\tMin:${min}`);
    }); */
};
processLine();