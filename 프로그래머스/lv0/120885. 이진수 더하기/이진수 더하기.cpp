#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(string bin1, string bin2) {
    string answer = "";
    
    int s1 = 0;
    int s2 = 0;
    int sum = 0;
    
    for (int i = bin1.length() - 1, j = 1; i >= 0; i--, j *= 2) {
        s1 += (bin1[i] - '0') * j;
    }
    
    for (int i = bin2.length() - 1, j = 1; i >= 0; i--, j *= 2) {
        s2 += (bin2[i] - '0') * j;
    }
    
    sum = s1 + s2;
    
    for (; sum != 0; sum = sum / 2) {
        answer = to_string(sum % 2) + answer;
    }
    
    if (answer.length() <= 0) { // sum이 0일 경우, for문이 동작하지 않음
        answer = "0";
    }
    
    return answer;
}