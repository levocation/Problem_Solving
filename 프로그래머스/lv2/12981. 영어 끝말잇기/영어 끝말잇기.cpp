#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    
    map<string, bool> words_dict;
    
    for (int i = 0; i < words.size(); i++) {
        if (words[i].length() <= 1) {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        if (i > 0) {
            if (words[i-1][words[i-1].length() - 1] 
               != words[i][0] 
               || words_dict.find(words[i]) != words_dict.end()) {
                answer[0] = (i % n) + 1;
                answer[1] = (i / n) + 1;
                break;
            }
        }
        words_dict.insert({words[i], true});
    }

    return answer;
}