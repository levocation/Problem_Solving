#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array) {
    vector<int> answer;
    
    int max = -1, idx = -1;
    
    for (int i = 0; i < array.size(); i++) {
        if (array[i] > max) {
            max = array[i];
            idx = i;
        }
    }
    
    answer.emplace_back(max);
    answer.emplace_back(idx);
    
    return answer;
}