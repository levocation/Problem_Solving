#include <string>
#include <vector>
#include <queue>

using namespace std;

struct func {
    bool operator()(int a, int b) {
        if (a == -1) return true;
        else if (b == -1) return false;
        // -1 값의 경우, 무조건 마지막에 배치되어야 한다.

        return a > b;
        // 기본적으로는 내림차순 정렬
    }
};

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size(), 0);
    
    priority_queue<int, vector<int>, func> qu;
    // 키별로 탐색할 문자열이 몇 번째 인덱스에 존재하는지
    // 우선순위 큐를 이용하여 가장 작은 값이 top에 오도록 배치함
    
    for (int x = 0; x < targets.size(); x++) {
        for (int i = 0; i < targets[x].length(); i++) {
            qu = priority_queue<int, vector<int>, func>();
            for (string key : keymap) {
                if (key.find(targets[x][i]) == string::npos) {
                    qu.push(-1);
                } else {
                    qu.push(key.find_first_of(targets[x][i]) + 1);
                }
            }
            if (qu.top() == -1) {
                answer[x] = -1;
                break;
            } else {
                answer[x] += qu.top();
            }
        }
    }
    
    return answer;
}