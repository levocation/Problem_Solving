#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int num1, int num2) {
    string answer = my_string;
    
    char a = my_string[num1];
    char b = my_string[num2];
    
    answer[num1] = b;
    answer[num2] = a;
    
    return answer;
}