#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer = strings;
    
    sort(answer.begin(), answer.end(), [=, &n](string a, string b) {
        if (a[n] == b[n]) {
            int len = (a.length() > b.length() 
                       ? b.length() : a.length());
            int i;
            for (i = 0; i < len; i++) {
                if (a[i] < b[i]) return true;
                else if (a[i] > b[i]) return false;
            }
            return a.length() < b.length();
        } else {
            return a[n] < b[n];
        }
    });
    
    return answer;
}