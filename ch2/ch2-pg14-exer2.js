console.log("Hanxin");
const fs = require("fs");
const readline = require("readline");
const rl = readline.createInterface({
    input: fs.createReadStream(`${__dirname}/data/ch2-pg14-exer2.in`)
});

let counter = 1;
let mod3 = 0;
let mod5 = 0;
let mod7 = 0;

const processLine = async () => {
    for await (let input of rl) {
        if (counter === 1) {
            mod3 = parseInt(input);
            counter++;
            continue;
        }
        if (counter === 2) {
            mod5 = parseInt(input);
            counter++;
            continue;
        }
        if (counter === 3) {
            mod7 = parseInt(input);
            let isHit = false;
            let headCounter = 0;
            for (headCounter = mod7; headCounter < 100; headCounter += 7) {
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
    }
};
processLine();