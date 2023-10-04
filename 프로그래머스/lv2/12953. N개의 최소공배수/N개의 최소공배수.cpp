#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int solution(vector<int> arr) {
    int answer = 1;
    
    sort(arr.begin(), arr.end());
    
    if (arr.size() == 1) {
        answer = arr[0];
    } else {
        int val = lcm(arr[0], arr[1]);
        
        for (int i = 2; i < arr.size(); i++) {
            val = lcm(val, arr[i]);
        }
        answer = val;
    }
    
    return answer;
}