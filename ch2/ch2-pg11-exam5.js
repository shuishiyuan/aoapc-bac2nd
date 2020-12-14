console.log("Number data statics with async await");
const os = require("os");
const fs = require("fs");

const rs = fs.createReadStream("data/ch2-pg11-exam5.in");
const ws = fs.createWriteStream("data/ch2-pg11-exam5.out");

const rl = require("readline");
const frl = rl.createInterface({
    input: rs
});