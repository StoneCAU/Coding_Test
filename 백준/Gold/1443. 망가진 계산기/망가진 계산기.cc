#include <bits/stdc++.h>

using namespace std;

// d: 자릿수, p: 연산수
int d, p;
int M = -1;

void dfs(int cnt, int res, int start) {
	if (p == 0) {
		M = 1;
		return;
	}

	// 횟수 만큼 곱했을 때 종료
	if (cnt == p) {
		M = max(M, res);
		return;
	}

	// 이제 곱해야됨.
	// res = 곱한 결과로 바꾸어줌 
	for (int i = start; i <= 9; i++) {
		int cal = res * i;

		// 자리수 넘어가면 break;
		string str = to_string(cal);
		if (str.length() > d) break;

		//cout << str << "\n";

		dfs(cnt + 1, res * i, i);
	}
}

// 처음 1
// 2 ~ 9의 숫자를 계속 곱함
// 결과 값은 D자리 이하여야함
// P번을 곱해서 가장 큰 수는?
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	// 자릿수, 연산수
	cin >> d >> p;

	dfs(0, 1, 2);

	cout << M;
}