#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int answer = 0;

void dfs(vector<int> numbers, int target, int depth, int sum) {
    if (target == sum) {
        answer++;
        return;
    } else if (target < sum) {
        return;
    } else if (depth >= numbers.size()) {
        return;
    } else {
        dfs(numbers, target, depth + 1, sum + numbers[depth]);
        dfs(numbers, target, depth + 1, sum);
    }
}

int solution(vector<int> numbers, int target) {
    answer = 0;
    int sum = 0;
    int new_target = 0;
    
    for (int num : numbers) {
        sum += num;
    }
    
    if (sum < target) return 0;
    
    new_target = sum - target;
    
    if (new_target % 2 == 1) return 0;
    if (new_target == 0) return 1;
    
    new_target /= 2;
    
    dfs(numbers, new_target, 0, 0);
    
    return answer;
}