#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int arr[6][2] = {0,};
    
    int stu_count, max_count, gender, grade, answer = 0;
    
    cin >> stu_count >> max_count;
    
    for (int i = 0; i < stu_count; i++) {
        cin >> gender >> grade;
        
        arr[grade - 1][gender]++;
    }
    
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 2; j++) {
            answer += (arr[i][j] / max_count) + (arr[i][j] % max_count == 0 ? 0 : 1);
        }
    }
    
    cout << answer;
    
    return 0;
}