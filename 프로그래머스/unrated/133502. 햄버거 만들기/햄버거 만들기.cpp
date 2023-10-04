#include <string>
#include <vector>

using namespace std;

int make_hamburger(string str) {
    if (str.find("1231") == string::npos) return 0;
    str.replace(str.find("1231"), 4, "");
    return 1 + make_hamburger(str);
}

int solution(vector<int> ingredient) {
    int answer = 0;
    
    // string ingredient_str = "";
    // 벡터의 모든 원소를 string에 넣는다.
    
    // for (int i : ingredient) {
    //    ingredient_str += to_string(i);
    // }
    
    // 위 덧셈 연산은, 매우 오랜 시간이 걸린다는 것을 인지
    // 기존에 생각했던 방식대로,
    // vector를 하나 더 만들어서
    // 해당 vector에 값을 push한 후에,
    // 해당 값이 1이라면
    // 이전 3개의 값을 비교해서
    // 그 값이 1 2 3 1 이라면 (빵 야채 고기 빵)
    // 해당 원소 4개를 pop 하고 answer++
    
    vector<int> v;
    
    for (int i : ingredient) {
        v.emplace_back(i);
        if (v.size() >= 4 
            // v에 들어온 값의 개수가 4개도 채 안 된다면
            // 햄버거가 완성될 수 없기 때문
           && v[v.size() - 4] == 1 
           && v[v.size() - 3] == 2 
           && v[v.size() - 2] == 3 
           && v[v.size() - 1] == 1 ) {
            v.pop_back();
            v.pop_back();
            v.pop_back();
            v.pop_back();
            answer++;
        }
    }
    
    return answer;
}