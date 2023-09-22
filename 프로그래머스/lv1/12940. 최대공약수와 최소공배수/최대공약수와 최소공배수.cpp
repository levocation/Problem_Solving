#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    
    int gcd = 0;
    int lcm = 0;
    
    for (gcd = (n > m ? m : n); 
         !((n % gcd == 0) && (m % gcd == 0)); gcd--) {}
    
    n = n / gcd;
    m = m / gcd;
    
    lcm = n * m * gcd;
    
    answer.emplace_back(gcd);
    answer.emplace_back(lcm);
    
    return answer;
}