#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    
    vector<int> arr = array;
    sort(arr.begin(), arr.end());
    vector<int> range;
    
    for (int i = 0; i < arr.size(); i++) {
        range.emplace_back(abs(arr[i] - n));
    }
    
    int min = 2147483647;
    
    for (int i = 0; i < range.size(); i++) {
        if (range[i] < min) {
            min = range[i];
            answer = arr[i];
        }
    }
    
    return answer;
}