#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[9];
int visited[9];

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = num; i <= n; i++) {
			arr[cnt] = i;
			dfs(i, cnt + 1);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	dfs(1, 0);
}