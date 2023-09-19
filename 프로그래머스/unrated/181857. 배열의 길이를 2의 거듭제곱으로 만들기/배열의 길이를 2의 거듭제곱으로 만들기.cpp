#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    
    double len = arr.size();
    double temp = len;
    
    int i;
    
    while (temp != 1) {
        temp = temp / 2;
        if (temp != (double)((int)temp)) {
            
            for (i = 2; i < len; i *= 2) { } // len보다 크면서 가장 작은 2의 거듭제곱수 구하기
            len = i;
            
            for (i = 0; i < len - arr.size(); i++) {
                answer.emplace_back(0);
            }
            
            break;
        }
    }
    
    return answer;
}