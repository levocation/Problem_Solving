#include <string>
#include <vector>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    string str = "";
    
    for (int x = i; x <= j; x++) {
        str += to_string(x);
    }
    
    for (int i = 0; i < str.length(); i++) {
        if (str[i] - '0' == k) answer++;
    }
    
    return answer;
}