#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> score) {
    vector<int> answer;
    
    vector<double> avg;
    
    for (int i = 0; i < score.size(); i++) {
        avg.emplace_back((score[i][0] + score[i][1]) / 2.0);
        answer.emplace_back(1);
    }
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer.size(); j++) {
            if (avg[i] > avg[j]) {
                answer[j]++;
            }
        }
    }
    
    return answer;
}