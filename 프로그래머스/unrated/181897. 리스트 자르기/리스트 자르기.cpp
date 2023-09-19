#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list) {
    vector<int> answer;
    
    int a = 0, b = num_list.size() - 1, c = 1;
    
    if (n == 1 || n == 3 || n == 4) {
        b = slicer[1];
    }
    if (n == 2 || n == 3 || n == 4) {
        a = slicer[0];
    }
    if (n == 4) {
        c = slicer[2];
    }
    
    for (int i = a; i <= b; i += c) {
        answer.emplace_back(num_list[i]);
    }
    
    return answer;
}