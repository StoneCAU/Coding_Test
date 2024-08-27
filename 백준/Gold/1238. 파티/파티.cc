#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

#define INF 10000000

int n, m, x;
int M = 0;
vector<int> partyDist(1002);
vector<int> homeDist(1002);
int resDist[1002];
int nope[1002];

vector<vector<pair<int, int>>> node(1002);

vector<int> dijkstra(int start)
{
	vector<int> dist(1002);
	fill(&dist[0], &dist[0] + 1002, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	dist[start] = 0;

	pq.push({ 0, start });

	while (!pq.empty())
	{
		int cur_dist = pq.top().first;
		int cur_node = pq.top().second;

		pq.pop();

		if (dist[cur_node] < cur_dist) continue;

		for (int i = 0; i < node[cur_node].size(); i++)
		{
			int nxt_node = node[cur_node][i].first;
			int nxt_dist = cur_dist + node[cur_node][i].second;

			//cout << dist[cur_node] << " " << nxt_dist << "\n";

			if (dist[nxt_node] > nxt_dist)
			{
				dist[nxt_node] = nxt_dist;
				pq.push({ nxt_dist, nxt_node });
			}
		}
	}

	//for (int i = 0; i < n; i++) cout << dist[i] << "\n";

	return dist;

}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		node[a].push_back({ b,c });
	}

	// i -> x 가는 거리 저장
	for (int i = 1; i <= n; i++) 
	{
		partyDist = dijkstra(i); // 각 n개 정점 마다 x까지 가는데 최단거리(1->x, 2->x, ..., n->x)
		if (partyDist[x] == INF) {
			nope[x] = true; // 이동 못하는 것(INF)은 취급 안함
			continue;
		}
		resDist[i] += partyDist[x]; 
		fill(&partyDist[0], &partyDist[0] + 1002, INF);

	}

	// x -> i 가는 거리 계산
	homeDist = dijkstra(x); // (x->1, x->2, ..., x->n)

	for (int i = 1; i <= n; i++)
	{
		// x -> i 까지 가는 거리 저장
		if (homeDist[i] == INF) {
			nope[i] = true;
			continue;
		}
		resDist[i] += homeDist[i];
	}

	for (int i = 1; i <= n; i++)
	{
		//cout << resDist[i] << "\n";
		if (nope[i]) continue;
		if (M < resDist[i]) M = resDist[i];
	}

	cout << M;
}

