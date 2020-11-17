console.log("The 2nd approach of 7744(aabb) Problem");
for (let i = 11; i < 100; ++i) {
    let j = Math.pow(i, 2);
    if (j < 1000) {
        continue;
    }
    if (j > 10000) {
        break;
    }
    let k = Math.ceil(j / 100);
    let l = j % 100;
    if ((Math.ceil(k / 10) == k % 10) 
        && (Math.ceil(l / 10) == l % 10)) {
        console.log(`The 7744(aabb) number is: ${j} with the base ${i}`);
        console.log(`The value of k: ${k} and the value of l: ${l}`);
    }
}