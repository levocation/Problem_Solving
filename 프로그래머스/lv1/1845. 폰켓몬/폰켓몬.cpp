#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    
    map<int, bool> m;
    // map<ponketmon_number, count>
    
    int count = 0;
    
    for (int num : nums) {
        if (m.find(num) == m.end()) {
            m.insert({num, true});
            count++;
        }
    }
    
    if (nums.size() / 2 > count) {
        return count;
    } else {
        return nums.size() / 2;
    }
}