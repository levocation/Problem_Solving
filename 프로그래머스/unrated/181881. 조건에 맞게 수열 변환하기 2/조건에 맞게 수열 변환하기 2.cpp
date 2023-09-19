#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    vector<int> temp_1 = arr;
    vector<int> temp_2 = arr;
    
    do {
        for (int i = 0; i < temp_1.size(); i++) {
            if (temp_1[i] >= 50 && temp_1[i] % 2 == 0) {
                temp_1[i] /= 2;
            } else if (temp_1[i] < 50 && temp_1[i] % 2 == 1) {
                temp_1[i] = temp_1[i] * 2 + 1;
            }
        }
        
        if (temp_1 == temp_2) {
            break;
        } else {
            answer++;
            temp_2 = temp_1;
        }
    } while (1 == 1);
    
    
    return answer;
}