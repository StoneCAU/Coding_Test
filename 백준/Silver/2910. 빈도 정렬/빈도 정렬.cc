#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

unordered_map<int, int> order;

bool cmp(pair<int,int>& a, pair<int,int>& b) {
	if (a.second == b.second) {
		return order[a.first] < order[b.first];
	}
	return a.second > b.second;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, c;
	cin >> n >> c;

	unordered_map<int, int> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (!m[num]) {
			m[num] = 1;
			order[num] = i;
		}
		else m[num]++;
	}

	vector<pair<int, int>> v(m.begin(), m.end());

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].second; j++) {
			cout << v[i].first << " ";
		}
	}
}