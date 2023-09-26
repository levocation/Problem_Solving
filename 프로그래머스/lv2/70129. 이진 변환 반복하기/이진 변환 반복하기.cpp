#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int delete_zero_count = 0;
    // 제거한 0의 개수
    
    int try_count = 0;
    // 이진 변환 횟수
    
    int len = 0;
    // 0 제거 후 길이
    
    for (try_count = 0; s != "1"; try_count++) {
        len = 0;
        while (s.find("0") != string::npos) {
            s.replace(s.find("0"), 1, "");
            delete_zero_count++;
        }
        
        len = s.length();
        
        s = "";
        while (len != 0) {
            s = to_string(len % 2) + s;
            len /= 2;
        }
    }
    
    answer.emplace_back(try_count);
    answer.emplace_back(delete_zero_count);
    
    return answer;
}