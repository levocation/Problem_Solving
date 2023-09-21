#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int k) {
    int answer = 0;
    for (int i = 0; i < k - 1; i++, answer += 2) {
        if (answer + 2 >= numbers.size()) {
            answer -= numbers.size();
        }
    }
    
    return numbers[answer];
}