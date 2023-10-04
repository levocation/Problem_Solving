#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = s;
    
    vector<int> alphabet;
    // skip할 알파벳을 제외하고 모든 알파벳이 오름차순 정렬
    
    int skip_count = 0;
    
    for (int i = 0; i < 26; i++) {
        skip_count = 0;
        for (int j = 0; j < skip.length(); j++) {
            if ((char)('a' + i) == skip[j]) {
                skip_count++;
                break;
            }
        }
        if (skip_count == 0) {
            alphabet.emplace_back((char)('a' + i));
        }
    }
    
    for (char& ch : answer) {
        //ch = alphabet[((int)(ch - 'a') + index) % alphabet.size()];
        ch = alphabet[(find(alphabet.begin(), alphabet.end(), ch) - alphabet.begin() 
                       + index) % alphabet.size()];
        // ①. vector에서 ch의 itarator를 찾고 (find(alphabet.begin(), alphabet.end(), ch))
        // ②. 해당 위치에서 시작 itarator를 뺀 값이 
        // alphabet의 ch가 있는 위치이다. (① - alphabet.begin())
        // ③. 해당 위치에서 index만큼 뒤로 가고 (② + index)
        // ④. out of range일 수도 있으니 alphabet의 개수로 나눈 나머지값으로 바꿔주고
        // (③ % alphabett.size())
        // ⑤. 이것이 우리가 구하고자 하는 최종적인 alphabet의 index이다.
        // (alphabet[④])
    }
    
    return answer;
}