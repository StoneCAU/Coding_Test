#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF 99999999

int v, e, k;
vector<pair<int, int>> graph[300001];
vector<int> dist(20001);

void dijkstra()
{
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

	dist[k] = 0;

	pq.push({ 0, k });

	while (!pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;

		pq.pop();

		if (dist[cur_node] < cur_dist) continue;
		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			int nxt_node = graph[cur_node][i].first;
			int nxt_dist = cur_dist + graph[cur_node][i].second;

			if (nxt_dist < dist[nxt_node]) 
			{
				dist[nxt_node] = nxt_dist;
				pq.push({ nxt_dist, nxt_node});
			}
		}
	}

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e;
	cin >> k;

	for (int i = 1; i <= v; i++) dist[i] = INF;


	for (int i = 0; i < e; i++)
	{
		int U, V, W;

		cin >> U >> V >> W;

		graph[U].push_back({ V,W });
	}

	dijkstra();

	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF) cout << "INF\n";
		else cout << dist[i] << "\n";
	}

}

