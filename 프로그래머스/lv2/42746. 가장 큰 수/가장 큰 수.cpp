#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int a, int b) {
    string str1 = to_string(a);
    string str2 = to_string(b);
    
    return stoi(str1 + str2) > stoi(str2 + str1);
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), comp);
    
    for (int num : numbers) {
        if (answer == "0") {
            answer = to_string(num);
        } else {
            answer += to_string(num);
        }
    }
    
    return answer;
}