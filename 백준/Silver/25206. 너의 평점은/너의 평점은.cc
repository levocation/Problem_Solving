#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int loop = 20, len = 0;
    int score = 0, credit = 0;
    double sum = 0.0;
    char grade = ' ';

    string str;


    while (loop--) {
        getline(cin, str);
        len = str.length();
        if (str[len - 1] == 'P') {
            continue;
        }
        else if (str[len - 1] == '+') {
            grade = str[len - 2];
            credit = (int)(str[len - 6] - '0');
        }
        else if (str[len - 1] == '0') {
            grade = str[len - 2] + 32;
            credit = (int)(str[len - 6] - '0');
        }
        else {
            grade = 'F';
            credit = (int)(str[len - 5] - '0');
        }
        score += credit;
        switch (grade) {
        case 'A':
            sum += credit * 4.5;
            break;
        case 'a':
            sum += credit * 4.0;
            break;
        case 'B':
            sum += credit * 3.5;
            break;
        case 'b':
            sum += credit * 3.0;
            break;
        case 'C':
            sum += credit * 2.5;
            break;
        case 'c':
            sum += credit * 2.0;
            break;
        case 'D':
            sum += credit * 1.5;
            break;
        case 'd':
            sum += credit * 1.0;
            break;
        default:
            break;
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << abs(sum / score);

    return 0;
}