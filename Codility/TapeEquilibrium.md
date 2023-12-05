# 문제

$N$개의 정수로 구성된 배열 $A$가 존재한다.

임의의 정수 $P$에 대하여 $0 < P < N$ 일 때

$(A[0] + A[1] + ... + A[P - 1])$ 와 $(A[P] + A[P + 1] + ... + A[N - 1])$의 차이를 $F(P)$라고 할 때,
$F(P)$의 최솟값을 구하시오.

예를 들어, 배열 A가 다음과 같다고 하자.

```A = {3, 1, 2, 4, 3}```

이때에 가능한 $P$ 를 모두 구해보면

```
P = 1, F(P) = |3 - 10| = 7
P = 2, F(P) = |4 - 9| = 5
P = 3, F(P) = |6 - 7| = 1
P = 4, F(P) = |10 - 3| = 7
```

이고 이 중 최솟값인 ```1``` 을 반환해야 한다.

---------------------------------

# 풀이

문제에 나온 그대로 모든 경우의 수를 다 계산해서

그 중 최솟값을 return한다.

두 수 a, b가 있고, 배열 A의 길이 N과 P가 있다고 해보자.

a의 초기값을 ```A[0]```으로 하고

b의 초기값을 ```A[1] + A[2] + ... + A[N - 1]```로 하면

P = 1 일 때

```a = A[0] + A[1]``` 이고 이는 ```a + A[1]``` 과 같다.

```b = (A[1] + A[2] + .... + A[N - 1]) - A[1]``` 이고 이는 ```b - A[1]```과 같다.

이와 같은 방식으로 값을 누적해서 쌓아가면

P = X 일 때 (단, 0 < X < N)

```a = A[0] + A[1] + .... + A[X]``` 이고 이는 ```a + A[X]```와 같다.

```b = (A[1] + A[2] + .... + A[N - 1]) - A[1] - A[2] - ... - A[X]``` 이고 이는 ```b - A[X]```와 같다.

즉, X의 값을 ```1```부터 ```N - 1``` 까지 모두 대입해서 최솟값을 구하면 되는 것이다.

```cpp
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> &A) {
    int a = A[0];
    int b = 0;

    for (int i = 1; i < A.size(); i++) {
        b += A[i];
    }

    int difference = abs(b - a);

    for (int i = 1; i < A.size() - 1; i++) {
        a += A[i];
        b -= A[i];

        if (abs(b - a) < difference) {
            // 차이를 구할 때는 절댓값
            difference = abs(b - a);
        }
    }

    return difference;
}
```
<img width="370" alt="image" src="https://github.com/levocation/Algorithm_Slack_Study/assets/42001961/21dd010c-e558-4ee7-8b42-12b999d4951f">

<img width="289" alt="image" src="https://github.com/levocation/Algorithm_Slack_Study/assets/42001961/f0a21798-8ea9-4bb3-8ccf-03c07d2b037e">

<img width="267" alt="image" src="https://github.com/levocation/Algorithm_Slack_Study/assets/42001961/75970005-793c-4a41-a233-0b4eef8ac866">
