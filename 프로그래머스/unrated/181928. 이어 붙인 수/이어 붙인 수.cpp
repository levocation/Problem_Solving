#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    string odd = "";
    string even = "";
    
    for (int i : num_list) {
        if (i % 2 == 1) {
            odd += to_string(i);
        } else {
            even += to_string(i);
        }
    }
    
    answer = stoi(odd) + stoi(even);
    
    return answer;
}