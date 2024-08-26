#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF 10000001

int n, m;
int arr[101][101];


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	fill(&arr[0][0], &arr[0][0] + 101 * 101, INF);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		if (arr[a][b]) arr[a][b] = min(arr[a][b], c);
		else arr[a][b] = c;
	}

	// i번째 도시 경유
	for (int i = 1; i <= n; i++)
	{

		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;

			for (int k = 1; k <= n; k++)
			{
				if (j == k) arr[j][k] = 0;
				if (i == k) continue;

				arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == INF) cout << "0 ";
			else cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}

