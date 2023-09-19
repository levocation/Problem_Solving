#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> rank, vector<bool> attendance) {
    int answer = 0;
    
    vector<int> rank_idx; // 해당 학생의 번호가 들어감
    
    vector<int> v; // 학생의 등수가 들어감
    
    for (int i = 0; i < rank.size(); i++) {
        if (attendance[i]) {
            v.emplace_back(rank[i]);
            rank_idx.emplace_back(i);
        }
    }
    
    // 버블정렬 시작
    int temp = 0;
    
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size() - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
                
                temp = rank_idx[j];
                rank_idx[j] = rank_idx[j + 1];
                rank_idx[j + 1] = temp;
            }
        }
    }
    
    answer = rank_idx[0] * 10000 + rank_idx[1] * 100 + rank_idx[2];
    
    return answer;
}