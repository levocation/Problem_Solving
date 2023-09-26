#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    vector<int> treasure_map(n, 0);
    
    for (int i = 0; i < n; i++) {
        treasure_map[i] = arr1[i] | arr2[i];
    }
    
    string temp;
    
    for (int i = 0; i < n; i++) {
        temp = "";
        for (int j = 0; j < n; j++) {
            if (treasure_map[i] % 2 == 1) {
                temp = "#" + temp;
            } else {
                temp = " " + temp;
            }
            treasure_map[i] /= 2;
        }
        answer.emplace_back(temp);
    }
    
    return answer;
}