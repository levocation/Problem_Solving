#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    
    stringstream ss(s);
    string buffer;
    
    int max = -2147483648;
    int min = 2147483647;
    
    int temp;
    
    while (getline(ss, buffer, ' ')) {
        temp = stoi(buffer);
        if (temp > max) max = temp;
        if (temp < min) min = temp;
    }
    answer = to_string(min) + " " + to_string(max);
    return answer;
}