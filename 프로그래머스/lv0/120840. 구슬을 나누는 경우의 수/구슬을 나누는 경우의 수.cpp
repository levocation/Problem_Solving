#include <string>
#include <vector>

using namespace std;

__int128 fact(long long i) {
    if (i <= 1) return 1;
    return i * fact(i - 1);
}

__int128 solution(int balls, int share) {
    return fact(balls) / (fact(balls - share) * fact(share));
}