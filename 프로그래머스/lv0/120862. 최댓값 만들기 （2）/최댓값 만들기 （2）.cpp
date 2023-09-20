#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;
    
    vector<int> positive;
    vector<int> nagative;
    
    int positive_num = 0;
    int nagative_num = 0;
    
    for (int i : numbers) {
        if (i < 0) {
            nagative.emplace_back(i);
        } else {
            positive.emplace_back(i);
        }
    }
    
    if (positive.size() >= 1) {
        sort(positive.begin(), positive.end());
    
    
    positive_num = positive[positive.size() - 1]
                    * (positive.size() >= 2
                        ? positive[positive.size() - 2]
                        : 1);
    }
    
    if (nagative.size() >= 1) {
        nagative_num = nagative[0] * (
                        nagative.size() >= 2
                        ? nagative[1] : 1);
        sort(nagative.begin(), nagative.end());
    }
    
    if (positive_num > nagative_num) {
        answer = positive_num;
    } else if (positive_num < nagative_num) {
        answer = nagative_num;
    }
    
    if (positive.size() == 1 && nagative.size() == 1) {
        answer = positive[0] * nagative[0];
    }
    
    return answer;
}