#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF 999999999

int n, e;
int v1, v2;
int res;
int res1, res2, res3, res4;

vector<vector<pair<int, int>>> node(801);

int dijkstra(int start, int end)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dist(801);
	fill(&dist[0], &dist[0] + 801, INF);
	
	dist[start] = 0;

	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cur_node = pq.top().second;
		int cur_dist = pq.top().first;

		pq.pop();

		if (dist[cur_node] < cur_dist) continue;

		for (int i = 0; i < node[cur_node].size(); i++)
		{
			int nxt_node = node[cur_node][i].first;
			int nxt_dist = cur_dist + node[cur_node][i].second;

			if (dist[nxt_node] > nxt_dist)
			{
				dist[nxt_node] = nxt_dist;
				pq.push({ nxt_dist, nxt_node });
			}
		}
	}

	return dist[end];
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> e;

	for (int i = 0; i < e; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}
	
	cin >> v1 >> v2;

	if (!e) {
		cout << -1;
		return 0;
	}

	// 1 -> v1 -> v2 -> n
	res1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);

	// 1 -> v2 -> v1 -> n
	res2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

	// 1 -> v1 -> v2 -> v1 -> n
	res3 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

	// 1 -> v2 -> v1 -> v2 -> n
	res4 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, v2) + dijkstra(v2, n);

	res = min(min(res1, res2), min(res3,res4));

	if (res >= INF) res = -1;

	cout << res;
	
}


