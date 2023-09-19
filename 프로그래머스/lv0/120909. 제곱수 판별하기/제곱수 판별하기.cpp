#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    return (sqrt((double)n) - (int)(sqrt((double)n)) 
                   == 0 ? 1 : 2);
}