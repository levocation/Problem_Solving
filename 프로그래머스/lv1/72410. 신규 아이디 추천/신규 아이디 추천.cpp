#include <string>
#include <vector>
#include <ctype.h>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    string temp = "";
    
    for (char& ch : answer) {
        // 1단계 : new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
        if (ch >= 65 && ch <= 90) {
            ch = ch + 32;
        }
    }
    
    temp = answer;
    answer = "";
    
    for (char& ch : temp) {
        // 2단계 : new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 
        // 마침표(.)를 제외한 모든 문자를 제거합니다.
        if (isalpha(ch) || isdigit(ch) || ch == '-' 
           || ch == '_' || ch == '.') {
            answer += ch;
        }
    }
    
    while (answer.find("..") != string::npos) {
        // 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 
        // 하나의 마침표(.)로 치환합니다.
        answer.replace(answer.find(".."), 2, ".");
    }
    
    if (answer[0] == '.') {
    // 4단계 : new_id에서 마침표(.)가 처음에 위치한다면 제거합니다.
        answer.replace(0, 1, "");
    }
    if (answer[answer.size() - 1] == '.') {
    // 4단계 : new_id에서 마침표(.)가 끝에 위치한다면 제거합니다.
        answer.replace(answer.size() - 1, 1, "");
    }
    
    if (answer == "") {
    // 5단계 : new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
        answer = "a";
    }
    
    if (answer.length() >= 16) {
        // 6단계 : new_id의 길이가 16자 이상이면, 
        // new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
        answer = answer.substr(0, 15);
    }
    if (answer[answer.size() - 1] == '.') {
        // 만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면
        // 끝에 위치한 마침표(.) 문자를 제거합니다.
        answer.replace(answer.size() - 1, 1, "");
    }
    
    if (answer.length() <= 2) {
        // 7단계 new_id의 길이가 2자 이하라면,
        // new_id의 마지막 문자를
        // new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
        while (answer.length() < 3) {
            answer += answer[answer.length() - 1];
        }
    }
    
    
    
    return answer;
}