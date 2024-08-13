#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int t;
int visited[10001];

int D(int n)
{
	int res = n * 2;

	if (res > 9999) return res % 10000;
	else return res;
}

int S(int n)
{
	int res = n - 1;

	if (n == 0) return 9999;
	else return res;
}

int L(int n)
{
	int res = (n % 1000) * 10 + (n / 1000);

	return res;
}

int R(int n)
{
	int res = (n / 10) + (n % 10) * 1000;

	return res;
}

void bfs(int a, int b)
{
	queue<pair<int, string>> q;

	q.push({ a, "" });

	while (!q.empty())
	{
		int x = q.front().first;
		string op = q.front().second;

		q.pop();

		if (x == b) {
			cout << op << "\n";
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx;
			string t = op;

			if (i == 0) nx = D(x);
			else if (i == 1) nx = S(x);
			else if (i == 2) nx = L(x);
			else nx = R(x);

			if (nx < 0 || nx >= 10000) continue;
			if (visited[nx]) continue;

			if (i == 0) q.push({ nx, t += 'D'});
			else if (i == 1) q.push({ nx, t += 'S' });
			else if (i == 2) q.push({ nx, t += 'L' });
			else q.push({ nx, t += 'R' });

			visited[nx] = 1;

		}
	}
}



int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(NULL);

	cin >> t;

	for (int i = 0; i < t; i++)
	{
		fill(&visited[0], &visited[0] + 10001, 0);

		int a;
		int b;

		cin >> a >> b;

		bfs(a, b);

	}



}