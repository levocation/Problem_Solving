#include <string>
#include <vector>

using namespace std;

vector<int> solution(int numer1, int denom1, int numer2, int denom2) {
    vector<int> answer;
    
    int min = (denom1 < denom2 ? denom1 : denom2);
    int gcd = 0; // 최대공약수
    int lcm = 0; // 최소공배수
    
    for (gcd = min; !(denom1 % gcd == 0 && denom2 % gcd == 0); gcd--) {}
    
    lcm = (denom1 / gcd) * (denom2 / gcd) * gcd;
    // 최소공배수 구하는 공식
    // 두 자연수 A, B의 최대공약수를 gcd라고 하고
    // A / gcd = a, B / gcd = b 라고 하면
    // 최소공배수 = (A / gcd) * (B / gcd) * gcd
    // = a * b * gcd
    
    numer1 = numer1 * (lcm / denom1);
    numer2 = numer2 * (lcm / denom2);
    
    denom1 = lcm;
    denom2 = lcm;
    
    int sum_numer = numer1 + numer2;
    int sum_denom = lcm;
    
    min = (sum_numer < sum_denom ? sum_numer : sum_denom);
    
    for (gcd = min; !(sum_numer % gcd == 0 
                      && sum_denom % gcd == 0); 
                        gcd--) {}
    
    answer.emplace_back(sum_numer / gcd);
    answer.emplace_back(sum_denom / gcd);
    
    return answer;
}