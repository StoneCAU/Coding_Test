#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n;
int M = 0; // 루트 노드로 부터 가장 먼 거리
int V = 0; // 루트 노드로 부터 가장 거리가 긴 포인트
int visited[10002];

vector<vector<pair<int, int>>> node(10002);


void dfs(int s, int len) // s: 시작 노드, len: 거리 계산
{
	if (visited[s]) return;

	visited[s] = 1;

	if (M < len)
	{
		M = len;
		V = s;
	}

	for (int i = 0; i < node[s].size(); i++)
	{
		int nxt = node[s][i].first;
		int wei = node[s][i].second;

		dfs(nxt, len + wei);

	}
}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n-1; i++)
	{
		int a, b, c;

		cin >> a >> b >> c;

		node[a].push_back({ b,c });
		node[b].push_back({ a,c });
	}

	dfs(1, 0);

	fill(&visited[0], &visited[0] + 10002, 0);

	dfs(V, 0);

	cout << M;

}

