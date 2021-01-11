console.log("The 2nd approach of 7744(aabb) Problem");
for (let base = 11; base < 100; ++base) {
    let aabb = Math.pow(base, 2);
    if (aabb < 1000) {
        continue;
    }
    if (aabb > 9999) {
        break;
    }
    let highNum = Math.floor(aabb / 100);
    let lowNum = aabb % 100;
    if ((Math.floor(highNum / 10) == highNum % 10) 
        && (Math.floor(lowNum / 10) == lowNum % 10)) {
        console.log(`The 7744(aabb) number is: ${aabb} with the base ${base}`);
        console.log(`The valowNumue of highNum: ${highNum} and the valowNumue of lowNum: ${lowNum}`);
    }
}