#include <string>
#include <vector>

using namespace std;

vector<int> answer(2, 0);
// 0의 개수, 1의 개수

void recursive(vector<vector<int>>& arr, int x, int y, int size) {
    int sum = 0;
    
    if (size == 1) {
        answer[arr[y][x]]++;
        return;
    }
    
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            sum += arr[i][j];
        }
    }
    
    if (sum == 0) {
        answer[0]++;
        return;
    }
    if (sum == size * size) {
        answer[1]++;
        return;
    }
    
    recursive(arr, x, y, size / 2);
    recursive(arr, x + (size / 2), y, size / 2);
    recursive(arr, x, y + (size / 2), size / 2);
    recursive(arr, x + (size / 2), y + (size / 2), size / 2);
}

vector<int> solution(vector<vector<int>> arr) {
    answer = vector<int>(2, 0);
    
    recursive(arr, 0, 0, arr.size());
    
    return answer;
}