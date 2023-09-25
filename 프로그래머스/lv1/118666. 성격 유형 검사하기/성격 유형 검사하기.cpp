#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    unordered_map<char, int> m;
    // map<MBTI, count>
    
    m.insert({'R', 0});
    m.insert({'T', 0});
    m.insert({'C', 0});
    m.insert({'F', 0});
    m.insert({'J', 0});
    m.insert({'M', 0});
    m.insert({'A', 0});
    m.insert({'N', 0});
    
    vector<pair<char, char>> mbti_v;
    mbti_v.emplace_back(make_pair('R', 'T'));
    mbti_v.emplace_back(make_pair('C', 'F'));
    mbti_v.emplace_back(make_pair('J', 'M'));
    mbti_v.emplace_back(make_pair('A', 'N'));
    
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i] - 4 > 0) {
            // 두 MBTI 중 오른쪽 값을 선택
            m.find(survey[i][1])->second += (choices[i] - 4);
        } else if (choices[i] - 4 < 0) {
            // 두 MBTI 중 왼쪽 값을 선택
            m.find(survey[i][0])->second += ((choices[i] - 4) * -1);
        }
    }
    
    for (int i = 0; i < mbti_v.size(); i++) {
        if (m.find(mbti_v[i].first)->second 
            < m.find(mbti_v[i].second)->second) {
            answer += mbti_v[i].second;
        } else {
            answer += mbti_v[i].first;
        }
    }
    
    return answer;
}