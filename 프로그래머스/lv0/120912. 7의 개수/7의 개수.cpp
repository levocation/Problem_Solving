#include <string>
#include <vector>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    
    vector<string> arr;
    
    for (int num : array) {
        arr.emplace_back(to_string(num));
    }
    
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].length(); j++) {
            if (arr[i][j] == '7') answer++;
        }
    }
    
    return answer;
}