#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int changeNum(int num, int n, int digit) {
	int temp = (num % (int)pow(10, digit))
		- (num % (int)pow(10, digit - 1));
	return num - temp + (n * pow(10, digit - 1));
}

int isprime[10001] = { 0 };
set<int> prime_list;
set<int> loglog;
queue<pair<int, int>> q;

int main() {

	int t;
	cin >> t;
	int key1, key2;

	for (int i = 2; i <= 10000; i++) {
		if (isprime[i] == 1) continue;

		for (int j = i * i; j <= 10000; j += i) {
			isprime[j] = 1;
		}
		if (i >= 1000 && i <= 9999) {
			prime_list.insert(i);
		}
	}

	for (int i = 0; i < t; i++) {
		cin >> key1 >> key2;

		loglog.clear();
		q = queue<pair<int, int>>();

		pair<int, int> cur;
		bool success = false;
		q.push({ key1, 0 });

		while (!q.empty()) {
			cur = q.front(); q.pop();

			if (cur.first == key2) {
				cout << cur.second << '\n';
				success = true;
				break;
			}

			for (int n = 0; n <= 9; n++) {
				for (int digit = 1; digit <= 4; digit++) {
					int temp = changeNum(cur.first, n, digit);
					if (prime_list.find(temp) != prime_list.end()
						&& loglog.find(temp) == loglog.end()) {
						q.push({ temp, cur.second + 1 });
						loglog.insert(temp);
					}
				}
			}
		}
		if (!success) {
			cout << "Impossible\n";
		}
	}

	return 0;
}