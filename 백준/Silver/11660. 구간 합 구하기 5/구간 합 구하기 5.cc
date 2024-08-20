#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int pSum[1025][1025];

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;


	for (int i = 1; i <= n; i++)
	{
		int sum = 0;

		for (int j = 1; j <= n; j++)
		{
			int num;

			cin >> num;

			sum += num;

			pSum[i][j] = pSum[i - 1][j] + sum;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		int res;

		cin >> x1 >> y1 >> x2 >> y2;

		res = pSum[x2][y2] - pSum[x1 - 1][y2] - pSum[x2][y1 - 1] + pSum[x1 - 1][y1 - 1];

		cout << res << "\n";
	}
}

