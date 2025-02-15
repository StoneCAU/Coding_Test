#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[51][51];
vector<pair<int, int>> ch;
vector<pair<int, int>> home;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) home.push_back({ i,j });
			if (arr[i][j] == 2) ch.push_back({ i,j });
		}
	}

	vector<int> temp;
	vector<int> idx;

	for (int i = 0; i < ch.size(); i++) {
		if (i < m) temp.push_back(0);
		else temp.push_back(1);

		idx.push_back(i);
	}

	int minD = 100000000;

	do {
		// 치킨집 선택
		vector<pair<int, int>> sel;

		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == 0) {
				int index = idx[i];
				int x = ch[index].first;
				int y = ch[index].second;

				sel.push_back({ x, y });
			}
		}
		
		// 치킨 거리 계산
		int chD = 0; // 총 치킨 거리

		for (int i = 0; i < home.size(); i++) {
			int cal = 100000000;

			for (int j = 0; j < sel.size(); j++) {
				cal = min(cal, abs(sel[j].first - home[i].first) + abs(sel[j].second - home[i].second));
			}

			chD += cal;
		}

		minD = min(minD, chD);

	} while (next_permutation(temp.begin(), temp.end()));

	cout << minD;
}