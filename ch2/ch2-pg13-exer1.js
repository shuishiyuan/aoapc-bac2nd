console.log("Daffodil");
let counter = 0;
for (let num = 100; num <= 999; num++) {
    const left = Math.floor(num / 100);
    // const left = num / 100;
    const middle = Math.floor((num % 100) / 10);
    // const middle = (num % 100) / 10;
    const right = num % 10; 
    if (Math.pow(left, 3) + Math.pow(middle, 3) + Math.pow(right, 3) === num) {
        console.log(`The daffodil number ${++counter} is: ${num}`);
    }
}
