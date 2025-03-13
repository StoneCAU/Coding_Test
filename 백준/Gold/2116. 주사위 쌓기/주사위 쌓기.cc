#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;

	vector<vector<int>> v;

	for (int i = 0; i < n; i++) {
		vector<int> t;
		
		for (int j = 0; j < 6; j++) {
			int num;
			cin >> num;

			t.push_back(num);
		}

		v.push_back(t);
	}

	// 최댓값
	int maxSum = 0;

	// 1번째 주사위의 윗 면이 1~6일 때
	// CE, BD, AF => 짝
	// index로 따지면 (0,5), (1,3), (2,4)
	for (int i = 1; i <= 6; i++) {
		// 총 합
		int sum = 0;

		// 옆 면을 제외한 index
		vector<pair<int,int>> a;

		// 맞닿아야 하는 숫자
		int number = i;

		// 첫 주사위
		vector<int> first = v[0];
		int fidx;
		int ffidx;

		// number를 가진 index 계산
		for (int k = 0; k < first.size(); k++) {
			if (first[k] == number) {
				fidx = k;
				break;
			}
		}

		if (fidx == 0) ffidx = 5;
		else if (fidx == 1) ffidx = 3;
		else if (fidx == 2) ffidx = 4;
		else if (fidx == 3) ffidx = 1;
		else if (fidx == 4) ffidx = 2;
		else if (fidx == 5) ffidx = 0;

		a.push_back({ fidx, ffidx });

		// 두 번째 주사위 부터 계산
		for (int j = 1; j < n; j++) {
			// j번째 주사위
			vector<int> cur = v[j];

			// number를 가진 index
			int idx;

			// 반대편 맞닿을 면 index
			int aidx;

			// number를 가진 index 계산
			for (int k = 0; k < cur.size(); k++) {
				if (cur[k] == number) {
					idx = k;
					break;
				}
			}

			// 다음 맞닿을 면의 숫자 index 계산
			if (idx == 0) aidx = 5;
			else if (idx == 1) aidx = 3;
			else if (idx == 2) aidx = 4;
			else if (idx == 3) aidx = 1;
			else if (idx == 4) aidx = 2;
			else if (idx == 5) aidx = 0;

			// 다음 맞닿을 면의 숫자 계산
			number = cur[aidx];

			a.push_back({ idx, aidx });
		}

		// 이제 각 주사위에서 옆 면의 최댓값을 모두 골라보자
		for (int j = 0; j < n; j++) {
			int maxNum = 0;

			// 현재 주사위
			vector<int> c = v[j];

			// 현재 주사위의 윗,뒷면
			pair<int, int> p = a[j];

			for (int k = 0; k < c.size(); k++) {
				int num = c[k];

				if (num == c[p.first] || num == c[p.second]) continue;

				maxNum = max(maxNum, num);
			}

			sum += maxNum;
		}

		maxSum = max(maxSum, sum);
	}

	cout << maxSum;
}