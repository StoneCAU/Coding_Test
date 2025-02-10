#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	long long M = -10000000000;

	long long preSum[100001];

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (i == 0) {
			preSum[i] = num;
		}
		else preSum[i] = preSum[i - 1] + num;
	}

	for (int i = 0; i < n; i++) {
		if (i + k - 1 >= n) continue;
		long long sum;

		if (i == 0) sum = preSum[k - 1];
		else sum = preSum[i + k - 1] - preSum[i - 1];

		M = max(M, sum);
	}

	cout << M;
}