#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;
    
    vector<int> idx;
    
    for (int i = 0; i < number.size() - 3; i++) {
        idx.emplace_back(0);
    }
    for (int i = 0; i < 3; i++) {
        idx.emplace_back(1);
    }
    
    int sum = 0;
    
    do {
        sum = 0;
        for (int i = 0; i < idx.size(); i++) {
            if (idx[i] == 1) {
                sum += number[i];
            }
        }
        
        answer += (sum == 0);
    } while (next_permutation(idx.begin(), idx.end()));
    
    return answer;
}