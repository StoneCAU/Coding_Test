#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, k;
int minTime = 10000000;
int minCnt = 0;
int visited[1000002];

queue<pair<int, int>> q;

void bfs()
{
	// (위치, 시간)
	q.push({ n, 0 });

	while (!q.empty())
	{
		int x = q.front().first;
		int t = q.front().second;

		q.pop();

		visited[x] = 1;

		if (x == k)
		{
			if (minTime > t) {
				minCnt = 1;
				minTime = t;
			}
			else if (minTime == t) minCnt++;
		}

		if (x + 1 < 100001 && x + 1 >= 0 && !visited[x + 1]) {
			q.push({ x + 1, t + 1 });
		}
		if (x - 1 < 100001 && x - 1 >= 0 && !visited[x - 1]) {
			q.push({ x - 1, t + 1 });
		}
		if (x * 2 < 100001 && x * 2 >= 0 && !visited[x * 2]) {
			q.push({ x * 2, t + 1 });
		}
	}

}


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	bfs();

	cout << minTime << "\n";
	cout << minCnt;
	
}


