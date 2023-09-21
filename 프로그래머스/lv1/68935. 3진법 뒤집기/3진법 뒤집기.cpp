#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    string t1 = "";
    string t2 = "";
    long long n1 = 0;
    
    while (n != 0) {
        t1 = to_string(n % 3) + t1;
        n /= 3;
    }
    
    for (int i = 0; i < t1.length(); i++) {
        answer += (t1[i] - '0') * pow(3, i);
    }
    
//     n1 = stoi(t2);
    
//     for (int i = 0; n1 != 0; i++) {
//         answer += (n1 % 10) * pow(3, i);
//         n1 = n1 / 10;
//     }
    
    return answer;
}