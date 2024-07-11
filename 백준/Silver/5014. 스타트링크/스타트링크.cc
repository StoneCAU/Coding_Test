#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int F, S, G, U, D;
queue<int> q;
int visited[1000001];
int res;

void bfs(int x)
{
	int dx[] = { U, -D };

	q.push(x);

	while (!q.empty())
	{
		int xx = q.front();

		q.pop();

		for (int i = 0; i < 2; i++)
		{
			if (!dx[i]) continue;

			int nx = xx + dx[i];

			if (nx == G) {
				visited[nx] = visited[xx] + 1;
				res = nx;
				return;
			}
			if (nx < 1 || nx > F) continue;
			if (visited[nx]) continue;
			visited[nx] = visited[xx] + 1;
			q.push(nx);
		}
	}
}


int main() {

	cin >> F >> S >> G >> U >> D;

	bfs(S);

	if (S == G) {
		cout << 0;
		return 0;
	}
	else if(res != G) cout << "use the stairs";
	else cout << visited[G];
}