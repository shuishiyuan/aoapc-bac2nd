console.log("Number data statics with async await");
const os = require("os");
const fs = require("fs");

const rs = fs.createReadStream("data/ch2-pg11-exam5.in");
const ws = fs.createWriteStream("data/ch2-pg11-exam5.out");

const rl = require("readline");
const { once } = require("process");

let digit = 0;
let sum = 0;
let counter = 0;
let max = 0;
let min = 0;
// async function processLine() {
(async () => {
    const frl = rl.createInterface({
        input: rs
    });

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
    once('beforeExit', () => {
        console.log(`Counter:${counter}\tAverage:${(sum / counter).toFixed(3)}\tMax:${max}\tMin:${min}`);
        ws.write(`Counter:${counter}\tAverage:${(sum / counter).toFixed(3)}\tMax:${max}\tMin:${min}`);
    });
})();
// processLine();