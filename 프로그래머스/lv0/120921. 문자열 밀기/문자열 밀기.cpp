#include <string>
#include <vector>

using namespace std;

int solution(string A, string B) {
    int answer = 0;
    
    string temp = A;
    
    if (A == B) return answer;
    
    for (int i = 0; i < A.length(); i++) {
        temp = temp.substr(temp.length() - 1, 1)
            + temp.substr(0, temp.length() - 1);
        if (temp == B) return i + 1;
    }
    
    return -1;
}