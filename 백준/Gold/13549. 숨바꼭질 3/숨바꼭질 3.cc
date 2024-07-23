#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n, k;
int visited[100001];
int dx[] = { -1, 1 };

deque<int> dq;


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	fill(&visited[0], &visited[0] + 100001, -1);
	visited[n] = 0;


	dq.push_back(n);

	while (!dq.empty())
	{
		int x = dq.front();

		dq.pop_front();

		int nx = 2 * x;

		if (nx) {
			if (nx <= 100000 && visited[nx] == -1) {
				visited[nx] = visited[x];
				dq.push_front(nx);
			}
		}



		for (int i = 0; i < 2; i++)
		{
			int nx = x + dx[i];

			if (nx < 0 || nx>100000) continue;
			if (visited[nx] != -1) continue;
			visited[nx] = visited[x] + 1;
			dq.push_back(nx);		 
		}
	}


	cout << visited[k];
	
}