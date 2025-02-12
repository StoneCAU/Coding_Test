#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<vector<int>> v(101, vector<int>(101, -1));
	vector<pair<int, int>> c;

	int h, w;
	cin >> h >> w;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char ch;
			cin >> ch;

			if (ch == 'c') {
				v[i][j] = 0;
				c.push_back({ i, j });
			}
		}
	}
	
	for (int i = 0; i < c.size(); i++) {
		int x = c[i].first;
		int y = c[i].second;

		for (int j = y + 1; j < w; j++) {
			if (v[x][j] == 0) continue;
			v[x][j] = v[x][j - 1] + 1;
		}
	}

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << v[i][j] << " ";
		}
		cout << "\n";
	}

}