#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int s, int e) {
    string answer = my_string;
    
    for (int i = 0; i < e - s + 1; i++) {
        answer[i+s] = my_string[e-i];
    }
    
    return answer;
}