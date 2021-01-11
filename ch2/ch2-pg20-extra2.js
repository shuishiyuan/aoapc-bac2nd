console.log("What is the result?");

let i;
for (i = 0; i != 1.0; i += 0.1) {
    console.log(`${i}`);
    if (i > 2) {
        break;
    }
}