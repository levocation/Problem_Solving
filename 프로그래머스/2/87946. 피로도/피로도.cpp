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
            // for문을 전부 돌고 나왔을 경우, 모든 던전을 도는 데 성공했으므로
            // 이보다 던전을 많이 도는 경우의 수가 없으므로 break
            answer = i;
            break;
        }
    } while (next_permutation(idx.begin(), idx.end()));
    
    return answer;
}