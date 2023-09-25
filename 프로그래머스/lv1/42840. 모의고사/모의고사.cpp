#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<pair<int, int>> answer_count(3, make_pair(0, 0)); // 수포자가 찍맞한 점수
    for (int i = 0; i < 3; i++) {
        answer_count[i].first = i;
    }
    
    int mem1_choice[5] = {1, 2, 3, 4, 5};
    int mem2_choice[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int mem3_choice[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == mem1_choice[i % 5]) {
            answer_count[0].second++;
        }
        if (answers[i] == mem2_choice[i % 8]) {
            answer_count[1].second++;
        }
        if (answers[i] == mem3_choice[i % 10]) {
            answer_count[2].second++;
        }
    }
    
    // 가장 큰 숫자 구하기
    sort(answer_count.begin(), answer_count.end(), compare);
    
    answer.emplace_back(answer_count[0].first + 1);
    if (answer_count[0].second == answer_count[1].second) {
        answer.emplace_back(answer_count[1].first + 1);
    }
    if (answer_count[0].second == answer_count[2].second) {
        answer.emplace_back(answer_count[2].first + 1);
    }
    
    return answer;
}