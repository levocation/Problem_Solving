#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool comp(pair<int, double> a, pair<int, double> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    vector<int> failure(N, 0);
    // 스테이지별 실패한 사람 수
    
    for (int num : stages) {
        if (num <= N) {
            failure[num - 1]++;
        }
    }
    
    vector<pair<int, double>> rate;
    int member_count = stages.size();
    
    for (int i = 0; i < N; i++) {
        if (failure[i] == 0) {
            rate.emplace_back(make_pair(i+1, 0));
        } else {
            rate.emplace_back(make_pair(i+1, 
                                failure[i] / (double)member_count));
            member_count -= failure[i];
        }
    }
    
    sort(rate.begin(), rate.end(), comp);
    
    for (int i = 0; i < rate.size(); i++) {
        answer.emplace_back(rate[i].first);
    }    
    return answer;
}