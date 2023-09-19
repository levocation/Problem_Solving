#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> stk;
    
    for (int i = 0; i < arr.size(); i++) {
        if (stk.size() == 0) {
            stk.emplace_back(arr[i]);
        } else if (*(stk.end() - 1) < arr[i]) {
            stk.emplace_back(arr[i]);
        } else if (*(stk.end() - 1) >= arr[i]) {
            stk.erase(stk.end() - 1);
            i--;
        }
    }
    
    return stk;
}