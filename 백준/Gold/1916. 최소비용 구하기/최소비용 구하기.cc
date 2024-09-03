#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF 999999999

int n, m;
int start, dest;
int dist[1001];

vector<vector<pair<int,int>>> node(1001);

int dijkstra(int start, int dest)
{
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	
	dist[start] = 0;

	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;

		pq.pop();

		if (cur_dist > dist[cur_node]) continue;
		for (int i = 0; i < node[cur_node].size(); i++)
		{
			int nxt_node = node[cur_node][i].first;
			int nxt_dist = node[cur_node][i].second + cur_dist;

			if (dist[nxt_node] > nxt_dist)
			{
				dist[nxt_node] = nxt_dist;
				pq.push({ nxt_dist, nxt_node });
			}
		}
	}

	return dist[dest];
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		node[a].push_back({ b,c });
		// node[b].push_back({ a,c });
	}

	fill(&dist[0], &dist[0] + 1001, INF);

	cin >> start >> dest;

	cout << dijkstra(start, dest);
}


