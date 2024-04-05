#include <iostream>
#define MOD 1000000009

using namespace std;
int dp[1000001] = { 0, };

int main() {
	int t;
	cin >> t;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	//dp[4] = 7;
	//dp[5] = 13;
	for (int i = 4; i <= 1000000; i++) {
		dp[i] = ((dp[i - 1] + dp[i - 2]) % MOD + dp[i - 3]) % MOD;
	}

	while (t--)
	{
		int num;
		cin >> num;
		cout << dp[num] << "\n";
	}

	return 0;
}