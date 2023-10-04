#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    vector<int> yellow_len;
    
    for (int i = yellow; i >= 1; i--) {
        if (yellow % i == 0) {
            yellow_len.emplace_back(i);
        }
    }
    
    int width = 0; // 노랑타일 가로길이
    int height = 0; // 노랑타일 세로길이
    
    for (int i = 0; i <= yellow_len.size() / 2; i++) {
        width = yellow_len[i];
        height = yellow_len[yellow_len.size() - 1 - i];
        
        if ((width + 2) * 2 + height * 2 == brown) {
            answer.emplace_back(width + 2);
            answer.emplace_back(height + 2);
            break;
        }
    }
    
    return answer;
}