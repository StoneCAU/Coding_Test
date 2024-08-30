#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF 10001

int tc, n, m, w;
int s, e, t;
int dist[501];

bool bf(vector<pair<pair<int, int>, int>> node)
{
	fill(&dist[0], &dist[0] + 501, INF);

	// n-1번 반복
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < node.size(); j++)
		{
			int from = node[j].first.first;
			int to = node[j].first.second;
			int time = node[j].second;

			if (dist[from] == INF) dist[from] = 0;

			if (dist[to] > dist[from] + time)
			{
				dist[to] = dist[from] + time;
			}
		}
	}

	for (int j = 0; j < node.size(); j++)
	{
		int from = node[j].first.first;
		int to = node[j].first.second;
		int time = node[j].second;

		if (dist[to] > dist[from] + time)
		{
			dist[to] = dist[from] + time;
			return true;
		}
	}

	return false;

}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		vector<pair<pair<int, int>, int>> node(501);

		cin >> n >> m >> w;

		// 도로의 정보
		for (int j = 0; j < m; j++)
		{
			cin >> s >> e >> t;
			node.push_back({ { s, e }, t });
			node.push_back({ { e, s }, t });
		}

		// 웜홀의 정보
		for (int j = 0; j < w; j++)
		{
			cin >> s >> e >> t;
			node.push_back({ { s, e }, -t });
		}

		if (bf(node)) cout << "YES\n";
		else cout << "NO\n";

	}
	

}


