#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	int n, t, sc, sum = 0;
    cin >> n;
    vector<vector<int>> score(n, vector<int>());
    cout.precision(3);
    while (n--) {
        cin >> t;
        sum = 0;
        score[n] = vector<int>(t);
        for (int i = 0; i < t; i++) {
            cin >> sc;
            score[n][i] = sc;
            sum += sc;
        }
        
        double avg = (double)sum / (double)t;
        double a = 0;
        for (int i = 0; i < t; i++) {
            if (score[n][i] > avg) a++;
        }
        cout << a / t * 100 << "%" << '\n';
    }
    

}