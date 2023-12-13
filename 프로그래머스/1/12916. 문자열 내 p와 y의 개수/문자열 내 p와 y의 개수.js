function solution(s) {
    var p = 0, y = 0;
    
    for (let ch of s) {
        if (ch == 'p' || ch == 'P') p++;
        else if (ch == 'y' || ch == 'Y') y++;
    }

    return (p == y);
}