#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(int a, int b) {
    if (abs(a) == abs(b)) {
        return a < b;
    } else {
        return abs(a) < abs(b);
    }
}

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    vector<int> v; // n과의 차이를 나타냄
    map<int, int> m; // 차이값, 인덱스번호
    
    for (int i = 0; i < numlist.size(); i++) {
        v.emplace_back(n - numlist[i]);
        m.insert({n - numlist[i], i});
    }
    
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < v.size(); i++) {
        answer.emplace_back(
            numlist[m.find(v[i])->second]
        );
    }
    
    return answer;
}