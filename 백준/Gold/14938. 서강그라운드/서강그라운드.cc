#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF 999999999

int n, m, r; // 지역의 개수(n), 수색범위(m), 길의 개수(r)
int item[101]; // 각 지역 n에 존재하는 아이템의 수
int dist[101][101];
int cnt = 0; // 얻을 수 있는 아이템의 수
int M = 0; // 최대 아이템 수

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> r;	
	
	fill(&dist[0][0], &dist[0][0] + 101 * 101, INF);


	for (int i = 1; i <= n; i++)
	{
		cin >> item[i];
	}

	for (int i = 0; i < r; i++)
	{
		int a, b, l;

		cin >> a >> b >> l;

		dist[a][b] = l;
		dist[b][a] = l;
	}

	for (int i = 1; i <= n; i++)
	{
		dist[i][i] = 0;
	}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int sum = item[i];

		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (dist[i][j] > m) continue;
			sum += item[j];
		}

		if (sum > M) M = sum;
	}

	cout << M;

}


