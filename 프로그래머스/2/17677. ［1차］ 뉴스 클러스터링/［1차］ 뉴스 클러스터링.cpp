#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    
    int A = 0;
    int B = 0;
    int intersection = 0;
    
    map<string, int> str2_word_dict;
    
    for (char& ch : str1) {
        ch = toupper(ch);
    }
    for (char& ch : str2) {
        ch = toupper(ch);
    }
    
    string tmp;
    
    for (int i = 0; i < str2.length() - 1; i++) {
        if (!isalpha(str2[i])) continue;
        if (!isalpha(str2[i + 1])) continue;
        
        tmp = str2[i];
        tmp += str2[i + 1];
        
        B++;
        
        if (str2_word_dict.find(tmp) == str2_word_dict.end()) {
            str2_word_dict.insert({tmp, 1});
        } else {
            str2_word_dict.find(tmp)->second++;
        }
    }
    
    for (int i = 0; i < str1.length() - 1; i++) {
        if (!isalpha(str1[i])) continue;
        if (!isalpha(str1[i + 1])) continue;
        
        tmp = str1[i];
        tmp += str1[i + 1];
        
        A++;
        
        if (str2_word_dict.find(tmp) != str2_word_dict.end()) {
            str2_word_dict.find(tmp)->second--;
            intersection++;
            
            if (str2_word_dict.find(tmp)->second <= 0) {
                str2_word_dict.erase(tmp);
            }
        }
    }
    
    double t = intersection;
    
    t = t / (double)(A + B - intersection);
    
    if (A == 0 && B == 0) {
        t = 1;
    }
    
    answer = (int)(t * 65536);
    
    return answer;
}