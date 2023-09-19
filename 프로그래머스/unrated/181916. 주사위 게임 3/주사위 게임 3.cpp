#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int a, int b, int c, int d) {
    int answer = 0;
    
    vector<int> v = {a, b, c, d};
    sort(v.begin(), v.end()); // 정렬
    
    int temp = 0;
    
    if (a == b && b == c && c == d && d == a) {
        // 모두 같은 숫자
        answer = 1111 * a;
    } else if (a != b && b != c && c != d && d != a && a != c 
               && b != d) {
        // 모두 다른 숫자
        answer = v[0];
    } else if ((a ^ b ^ c ^ d) == 0) {
        // 두 개씩 같은 숫자
        // v = {a <= b <= c <= d} 인데
        // 두 개씩 같은 숫자가 있다고 했으므로
        // 가능한 경우의 수는 a == b, c == d 밖에 없다.
        answer = (v[0] + v[2]) * abs(v[0] - v[2]);

    } else {
        if (v[0] == v[1]) {
            if (v[1] == v[2]) {
                // v[0] == v[1] == v[2], v[3]
                answer = (10 * v[0] + v[3]) * (10 * v[0] + v[3]);
            } else {
                // v[0] == v[1], v[2], v[3]
                answer = v[2] * v[3];
            }
        } else if (v[1] == v[2]) {
            if (v[2] == v[3]) {
                // v[0], v[1] == v[2] == v[3]
                answer = (10 * v[1] + v[0]) * (10 * v[1] + v[0]);
            } else {
                // v[0], v[1] == v[2], v[3]
                answer = v[0] * v[3];
            }
        } else if (v[2] == v[3]) {
            // v[0], v[1], v[2] == v[3]
                answer = v[0] * v[1];
        }
    }
    
    return answer;
}