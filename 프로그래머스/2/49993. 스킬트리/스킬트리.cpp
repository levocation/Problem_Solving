#include <string>
#include <vector>
#include <regex>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    int index = 0;
    
    bool isSkillTree = true;
    
    for (string str : skill_trees) {
        isSkillTree = true;
        index = 0;
        for (int i = 0; i < str.length(); i++) {
            if (skill.find(str[i]) != string::npos) {
                if (str[i] == skill[index]) {
                    index++;
                } else {
                    isSkillTree = false;
                    break;
                }
            }
        }
        answer += (int)(isSkillTree);
    }
    
    return answer;
}