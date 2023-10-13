#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    int tangerine_count = 0;
    
    int arr[10000000] = {0,};
    
    for (int num : tangerine) {
        arr[num-1]++;
    }
    
    sort(arr, arr + 10000000, greater<int>());
    
    for (int i = 0; i < 10000000; i++) {
        tangerine_count += arr[i];
        
        if (tangerine_count >= k) {
            answer = i + 1;
            break;
        }
    }
    
    return answer;
}