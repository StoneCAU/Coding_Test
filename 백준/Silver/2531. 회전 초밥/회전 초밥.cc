#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int n, d, k, c;
unordered_map<int, int> m;

int main() {
	cin >> n >> d >> k >> c;
	int M = 0;
	vector<int> v;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	// 처음 k만큼 먹었을 때
	for (int i = 0; i < k; i++) {
		m[v[i]]++;
	}

	// max 값 초기화
	M = m.size();
	if (!m[c]) M++;

	// 맨 앞에 있는 초밥
	int idx = 0;

	for (int i = k; i < n + k; i++) {
		// 맨 앞 요소 제거
		m[v[idx % n]]--;
		
		if (m[v[idx % n]] == 0) {
			m.erase(v[idx % n]);
		}

		idx++;

		// 새로운 요소 삽입 
		int cur = v[i % n];
		m[cur]++;

		// 보너스 초밥 고려
		if (!m[c]) {
			m.erase(c);
			M = max(M, (int)m.size() + 1);
		}
		else M = max(M, (int)m.size());

	}

	cout << M;
}