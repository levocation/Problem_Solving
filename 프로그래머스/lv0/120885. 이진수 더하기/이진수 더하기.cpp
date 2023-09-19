#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(string bin1, string bin2) {
    
    // 로직 요약
    // bin1과 bin2를 10진수로 만들고
    // 두 값을 더한 뒤에 2진수로 변환한다.
    
    string answer = "";
    
    int s1 = 0;
    int s2 = 0;
    int sum = 0;
    
    // bin1을 10진수 정수로 변환하는 작업
    for (int i = bin1.length() - 1, j = 1; i >= 0; i--, j *= 2) {
        // 맨 뒷자리부터 2⁰, 2¹, 2², .... 2ⁿ을 해당 자리에 있는 숫자에 곱해서 s1에 더해준다.
        s1 += (bin1[i] - '0') * j;
    }
    
    // bin2를 10진수 정수로 변환하는 작업
    for (int i = bin2.length() - 1, j = 1; i >= 0; i--, j *= 2) {
        // 맨 뒷자리부터 2⁰, 2¹, 2², .... 2ⁿ을 해당 자리에 있는 숫자에 곱해서 s2에 더해준다.
        s2 += (bin2[i] - '0') * j;
    }
    
    // bin1(10진수) + bin2(10진수)
    sum = s1 + s2;
    
    // 2로 나눈 나머지를 맨 앞자리에 넣어준다.
    for (; sum != 0; sum = sum / 2) {
        answer = to_string(sum % 2) + answer;
    }
    
    if (answer.length() <= 0) { // sum이 0일 경우, for문이 동작하지 않음
        answer = "0";
    }
    
    return answer;
}