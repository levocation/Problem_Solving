#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    
    answer.emplace_back(money / 5500);
    answer.emplace_back(money % 5500);
    
    return answer;
}