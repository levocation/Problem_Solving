#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    
    vector<int> idx;
    
    for (int i = 0; i < nums.size() - 3; i++) {
        idx.emplace_back(0);
    }
    for (int i = 0; i < 3; i++) {
        idx.emplace_back(1);
    }
    
    int sum = 0;
    bool isSosu = true;
    do {
        sum = 0;
        isSosu = true;
        for (int i = 0; i < nums.size(); i++) {
            if (idx[i] == 1) {
                sum += nums[i];
            }
        }
        
        for (int i = 2; i < sqrt(sum) + 1; i++) {
            if (sum % i == 0) {
                isSosu = false;
                break;
            }
        }
        answer += isSosu;
    } while (next_permutation(idx.begin(), idx.end()));

    return answer;
}