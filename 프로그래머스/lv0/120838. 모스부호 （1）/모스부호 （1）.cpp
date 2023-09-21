#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

string solution(string letter) {
    string answer = "";
    
    map<string, char> m;
    
    m.insert({".-",'a'});
    m.insert({"-...",'b'});
    m.insert({"-.-.",'c'});
    m.insert({"-..",'d'});
    m.insert({".",'e'});
    m.insert({"..-.",'f'});
    m.insert({"--.",'g'});
    m.insert({"....",'h'});
    m.insert({"..",'i'});
    m.insert({".---",'j'});
    m.insert({"-.-",'k'});
    m.insert({".-..",'l'});
    m.insert({"--",'m'});
    m.insert({"-.",'n'});
    m.insert({"---",'o'});
    m.insert({".--.",'p'});
    m.insert({"--.-",'q'});
    m.insert({".-.",'r'});
    m.insert({"...",'s'});
    m.insert({"-",'t'});
    m.insert({"..-",'u'});
    m.insert({"...-",'v'});
    m.insert({".--",'w'});
    m.insert({"-..-",'x'});
    m.insert({"-.--",'y'});
    m.insert({"--..",'z'});
    
    stringstream ss(letter);
    string buffer;
    
    while (getline(ss, buffer, ' ')) {
        answer += m.find(buffer)->second;
    }
    
    return answer;
}