console.log("The 1st approach of 7744(aabb) Problem");
let n = 0;
for (let i = 1; i <=9; ++i) {
    for (let j = 0; j <= 9; ++j) {
        n = 1100 * i + 11 * j;
        // sqt = Math.sqrt(n);
        sqt = Math.ceil(Math.sqrt(n));
        if (n === Math.pow(sqt, 2)) {
            console.log(`One of the 7744(aabb) number is: ${n} with the sqrt value ${sqt}`);
        }
    }
}