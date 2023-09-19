#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr1, vector<int> arr2) {
    int answer = 0;
    
    int s1 = 0, s2 = 0;
    
    if (arr1.size() > arr2.size()) { // arr1 배열 길이가 더 길다면
        answer = 1;
    } else if (arr1.size() < arr2.size()) { // arr2 배열 길이가 더 길다면
        answer = -1;
    } else { // 같다면
        for (int i : arr1) { // arr1의 합계
            s1 += i;
        }
        
        for (int i : arr2) { // arr2의 합계
            s2 += i;
        }
        
        // 대소비교
        if (s1 > s2) {
            answer = 1;
        } else if (s1 < s2) {
            answer = -1;
        } else {
            answer = 0;
        }
    }
    
    return answer;
}