#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int key = -1;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] != key) {
            answer.emplace_back(arr[i]);
            key = arr[i];
        }
    }
    
    return answer;
}