#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    string str;
    bool isFiveAndZero;
    
    for (int i = l; i <= r; i++) {
        if (i % 5 != 0) continue;
        str = to_string(i);
        isFiveAndZero = true;
        
        for (char ch : str) {
            if (ch != '5' && ch != '0') {
                isFiveAndZero = false;
                break;
            }
        }
        if (isFiveAndZero) {
            answer.emplace_back(i);
        } else continue;
    }
    
    if (answer.size() == 0) answer.emplace_back(-1);
    
    return answer;
}