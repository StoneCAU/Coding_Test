#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[9];
int visited[9];
vector<int> num;

void dfs(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < n; i++) {
			arr[cnt] = num[i];
			dfs(i, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		num.push_back(a);
	}

	sort(num.begin(), num.end());

	dfs(0, 0);
}