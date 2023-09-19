#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, int n) {
    vector<int> answer = arr;
    
    for (int i = (arr.size() % 2 == 1 ? 0 : 1); i <= arr.size(); i += 2) {
        answer[i] += n;
    }
    
    return answer;
}