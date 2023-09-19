#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int size = num_list.size();
    
    for (int i = 0; i < size; i++) {
        if (size >= 11) answer += num_list[i];
        else {
            if (answer == 0) answer = 1;
            answer *= num_list[i];
        }
    }
    
    return answer;
}