#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    
    vector<int> v = sides;
    sort(v.begin(), v.end());
    
    if (v[0] + v[1] > v[2]) {
        answer = 1;
    } else {
        answer = 2;
    }
    
    return answer;
}