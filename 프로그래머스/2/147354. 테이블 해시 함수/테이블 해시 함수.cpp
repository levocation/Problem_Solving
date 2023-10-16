#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int column = 0;

bool comp(vector<int> a, vector<int> b) {
    if (a[column] == b[column]) return a[0] > b[0];
    return a[column] < b[column];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    column = col - 1;
    
    sort(data.begin(), data.end(), comp);
    
    int sum = 0;
    for (int i = row_begin; i <= row_end; i++) {
        sum = 0;
        for (int num : data[i - 1]) {
            sum += num % i;
        }
        answer = answer ^ sum;
    }
    
    return answer;
}