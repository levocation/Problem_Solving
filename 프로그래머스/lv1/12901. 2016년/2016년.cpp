#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    
    int daycount = 0;
    // 1월 1일로부터 며칠이 지났는가
    
    vector<int> month_daycount = {31, 29, 31, 30, 31, 30, 31, 
                                 31, 30, 31, 30, 31};
    // 월마다 몇 일만큼 존재하는가
    
    for (int i = 2; i <= a; i++) {
        daycount += month_daycount[i - 2];
    }
    // 2월부터는 이전 월의 일수를 더해준다.
    
    daycount += b;
    // 해당 월 안에서 며칠이 지났는지 그 값을 더한다.
    
    switch (daycount % 7) {
        // 요일을 구하기 위해 7로 나눈 나머지값을 계산
        case 1:
            answer = "FRI";
            // 지문에서 제시한 기본값
            break;
        case 2:
            answer = "SAT";
            break;
        case 3:
            answer = "SUN";
            break;
        case 4:
            answer = "MON";
            break;
        case 5:
            answer = "TUE";
            break;
        case 6:
            answer = "WED";
            break;
        case 0:
            answer = "THU";
            break;
    }
    
    return answer;
}