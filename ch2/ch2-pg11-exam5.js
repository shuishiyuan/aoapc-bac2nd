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
let min = Number.MAX_SAFE_INTEGER;
// let min = 0x7fffffffffffffff;
// let min = Number.MAX_VALUE;
let max = Number.MIN_SAFE_INTEGER;
// let max = -0x8000000000000000;
// let max = Number.MIN_VALUE;
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