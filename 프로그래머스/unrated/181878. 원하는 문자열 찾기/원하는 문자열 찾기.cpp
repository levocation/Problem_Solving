#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    string ms = "";
    string pt = "";
    
    for (int i = 0; i < myString.size(); i++) {
        ms += toupper(myString[i]);
    }
    
    for (int i = 0; i < pat.size(); i++) {
        pt += toupper(pat[i]);
    }
    
    if (ms.find(pt) != string::npos) {
        return 1;
    }
    
    return answer;
}