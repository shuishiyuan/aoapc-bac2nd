console.log("Hanxin");
const fs = require("fs");
const readline = require("readline");
const rl = readline.createInterface({
    input: fs.createReadStream(`${__dirname}/input/ch2-pg14-exer2.in`)
});

let counter = 1;
let mod3 = 0;
let mod5 = 0;
let mod7 = 0;

const processLine = async () => {
    await for (let input of rl) => {
        if (counter++ === 1) {
            mod3 = input;
            continue;
        }
        if (counter++ === 2) {
            mod5 = input;
            continue;
        }
        if (counter === 3) {
            mod7 = input;
            let isHit = false;
            for (let headCounter = mod7; headCounter < 10000; headCounter += mod7) {
                if (headCounter % 3 != mod3) {
                    continue;
                }
                if (headCounter % 5 === mod5) {
                    isHit = true;
                    break;
                }
            }
            console.log(isHit ? `Head Count is: ${headCounter}` : `There is no answer`);
        }
    };
}
processLinee();