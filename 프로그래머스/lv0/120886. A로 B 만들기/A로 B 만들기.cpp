#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string before, string after) {
    int answer = 0;
    
    string str1 = before;
    string str2 = after;
    
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    
    return (str1 == str2);
}