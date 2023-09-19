#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    
    int s = -1;
    int e = -1;
    int k = -1;
    
    int temp = -1;
    
    for (int i = 0; i < queries.size(); i++) {
        s = queries[i][0];
        e = queries[i][1];
        k = queries[i][2];
        temp = -1;
        
        for (int j = s; j <= e; j++) {
            if (arr[j] > k) {
                if (temp == -1) temp = arr[j];
                else if (temp > arr[j]) temp = arr[j];
            }
        }
        answer.emplace_back(temp);
    }
    
    return answer;
}