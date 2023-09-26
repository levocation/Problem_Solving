#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer(2, 0);
    // {high_rank, low_rank}
    
    int blank_count = 0;
    
    for (int i = 0; i < 6; i++) {
        if (lottos[i] == 0) {
            blank_count++;
            continue;
        }
        for (int j = 0; j < 6; j++) {
            if (lottos[i] == win_nums[j]) {
                answer[0]++;
                answer[1]++;
                break;
            }
        }
    }
    
    answer[0] += blank_count;
    
    for (int& num : answer) {
        if (num == 0) {
            num = 6;
        } else {
            num = 7 - num;
        }
    }
    
    return answer;
}