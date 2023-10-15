#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    
    int fatigue = k;
    // 피로도
    
    int i = 0;
    int dungeons_size = dungeons.size();
    
    vector<int> idx;
    
    for (int i = 0; i < dungeons_size; i++) {
        idx.emplace_back(i);
    }
    
    do {
        fatigue = k;
        
        for (i = 0; i < dungeons_size; i++) {
            if (fatigue >= dungeons[idx[i]][0] && fatigue >= dungeons[idx[i]][1]) {
                fatigue -= dungeons[idx[i]][1];
            } else {
                if (i > answer) {
                    answer = i;
                }
                break;
            }
        }
        
        if (i >= dungeons_size) {
            answer = i;
            break;
        }
    } while (next_permutation(idx.begin(), idx.end()));
    
    return answer;
}