console.log("The PI / 4 approximate value Problem");

let sum = 1;
let entry = 1;

let i = 1;
do {
    entry = 1 / (i * 2 + 1);
    if (i % 2 == 1) {
        sum -= entry;
    } else {
        sum += entry;
    }
    i++;
// } while(entry > 1e-6)
} while(entry > 0.0001)

console.log(`The approximated value of PI / 4 is: ${sum}`);