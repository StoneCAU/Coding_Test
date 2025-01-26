#include <bits/stdc++.h>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int miro[1001][1001];
	int visited[1001][1001];

	int dx[] = { 1,0,1 };
	int dy[] = { 0,1,1 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> miro[i][j];
		}
	}

	visited[0][0] = miro[0][0];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0) visited[i][j] = visited[i][j - 1] + miro[i][j];
			if (j == 0) visited[i][j] = visited[i - 1][j] + miro[i][j];
			else visited[i][j] = max(visited[i - 1][j], visited[i][j - 1]) + miro[i][j];
		}
	}



	cout << visited[n - 1][m - 1];

}