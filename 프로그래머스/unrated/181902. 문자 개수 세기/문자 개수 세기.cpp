#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    int int_ch = 0;
    
    for (char ch : my_string) {
        int_ch = (int)ch;
        if (int_ch < 97) { // 대문자
            answer[int_ch - 65]++;
        } else {
            answer[int_ch - 71]++;
        }
    }
    
    return answer;
}