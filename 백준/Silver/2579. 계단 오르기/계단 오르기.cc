#include <bits/stdc++.h>

using namespace std;

int main() {
	// 계단의 개수
	int n;
	cin >> n;

	// 각 계단의 점수
	int score[301];
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		score[i] = num;
	}

	// dp
	int arr[301];

	arr[1] = score[1];
	arr[2] = score[1] + score[2];
	arr[3] = score[3] + max(score[1], score[2]);

	for (int i = 4; i <= n; i++) {
		arr[i] = score[i] + max(arr[i - 2], arr[i - 3] + score[i-1]);
	}

	cout << arr[n];

	return 0;
}