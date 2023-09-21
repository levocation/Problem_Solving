#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = numbers;
    for (int& i : answer) {
        i *= 2;
    }
    return answer;
}