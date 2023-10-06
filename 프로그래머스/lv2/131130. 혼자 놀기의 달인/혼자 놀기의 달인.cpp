#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> cards) {
    int answer = 0;
    
    vector<bool> isOpened(cards.size(), 0);
    vector<int> group;
    
    int i = cards[0] - 1;
    int count = 0;
    int box_count = cards.size();
    
    while (true) {
        if (isOpened[i]) {
            group.emplace_back(count);
            count = 0;
            if (box_count <= 0) {
                group.emplace_back(0);
                break;
            } else {
                for (int j = 0; j < cards.size(); j++) {
                    if (!isOpened[j]) {
                        i = j;
                        break;
                    }
                }
            }
        } else {
            isOpened[i] = true;
            i = cards[i] - 1;
            box_count--;
            count++;
        }
    }
    
    sort(group.begin(), group.end(), greater<int>());
    
    answer = group[0] * group[1];
    
    return answer;
}