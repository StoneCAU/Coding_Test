#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int v;
int visited[100001];
int M = 0;
int V;
int res;

vector<vector<pair<int, int>>> node(100001);

void dfs(int point, int len)
{
	if (visited[point]) return;

	visited[point] = 1;

	if (M < len)
	{
		M = len;
		V = point;
	}

	for (int i = 0; i < node[point].size(); i++)
	{
		int nxt_node = node[point][i].first;
		int nxt_dist = node[point][i].second;

		dfs(nxt_node, len + nxt_dist);
	}
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> v;

	for (int i = 0; i < v; i++)
	{
		// 정점 입력
		int a;

		cin >> a;
		
		// 간선 정보 입력
		while (1)
		{
			int b, c;

			cin >> b;

			if (b == -1) break;

			cin >> c;

			node[a].push_back({ b, c });
			node[b].push_back({ a, c });
		}
	}

	dfs(1, 0);

	fill(&visited[0], &visited[0] + 100001, 0);

	dfs(V, 0);

	cout << M;
}


