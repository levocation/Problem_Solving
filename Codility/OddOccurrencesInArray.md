
각 숫자별로 등장횟수를 해시에 담고,

이후 해시를 순회하면서 등장횟수가 홀수인 숫자를 찾아서 return한다.

```cpp
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A) {

    unordered_map<int, int> m;
    // map<숫자, 등장횟수>

    for (int i = 0; i < A.size(); i++) {
        if (m.find(A[i]) == m.end()) {
            // 해시 데이터에 존재하지 않는 숫자면

            m.insert({A[i], 1});
            // insert 한다.

        } else {
            // 해시 데이터에 존재하는 숫자면

            m.find(A[i])->second++;
            // 등장횟수 +1
        }
    }

    for (auto it = m.begin(); it != m.end(); it++) {
        if ((it->second) % 2 == 1) {
            // 등장횟수가 홀수라면

            return it->first;
            // 해당 숫자 return
        }
    }
}
```

![image](https://github.com/levocation/Algorithm_Slack_Study/assets/42001961/d8a2b364-d84f-415b-879e-f173a18546a9)

![image](https://github.com/levocation/Algorithm_Slack_Study/assets/42001961/0385f4b5-6854-45e1-b3f6-7893a2431777)
