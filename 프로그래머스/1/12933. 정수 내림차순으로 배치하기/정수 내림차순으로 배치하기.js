function solution(n) {
    n += "";
    let a = [];
    for (let ch of n) a.push(ch * 1);
    a.sort((a, b) => b - a);
    let b = "";
    for (let ch of a) b += ch;
    return b * 1;
}