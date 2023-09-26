#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    queue<string> words1;
    queue<string> words2;
    
    for (string str : cards1) {
        words1.push(str);
    }
    
    for (string str : cards2) {
        words2.push(str);
    }
    
    string word1 = "";
    string word2 = "";
    
    if (words1.empty()) {
        word1 = "";
    }
    else {
        word1 = words1.front();
        words1.pop();
    }

    if (words2.empty()) {
        word2 = "";
    }
    else {
        word2 = words2.front();
        words2.pop();
    }
    
    int idx = 0;
    
    while (true) {
        if (word1 == goal[idx]) {
            idx++;
            if (words1.empty()) {
                word1 = "";
            }
            else {
                word1 = words1.front();
                words1.pop();
            }
        } else if (word2 == goal[idx]) {
            idx++;
            if (words2.empty()) {
                word2 = "";
            }
            else {
                word2 = words2.front();
                words2.pop();
            }
        } else {
            if (idx >= goal.size()) answer = "Yes";
            else answer = "No";
            break;
        }
    }
    
    return answer;
}