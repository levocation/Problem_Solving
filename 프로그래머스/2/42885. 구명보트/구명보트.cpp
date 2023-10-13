#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int left_key = 0;
    int right_key = people.size() - 1;
    
    while (left_key < right_key) {
        if (people[left_key] + people[right_key] <= limit) {
            left_key++;
        }
        right_key--;
        answer++;
    }
    
    if (left_key == right_key) {
        answer++;
    }
    
    return answer;
}