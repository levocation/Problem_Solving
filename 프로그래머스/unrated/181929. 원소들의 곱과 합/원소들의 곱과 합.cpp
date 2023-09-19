#include <string>
#include <vector>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    int sum = 0;
    int multiply = 1;
    
    for (int i : num_list) {
        sum += i;
        multiply *= i;
    }
    
    if (sum * sum > multiply) {
        answer = 1;
    } else {
        answer = 0;
    }
    
    return answer;
}