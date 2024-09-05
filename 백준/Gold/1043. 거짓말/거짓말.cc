#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

int n, m;
int know;
int lie = 0;
int arr[51]; // 파티 배열
int visited[51];


// 진실을 아는 사람
queue<int> q;

// 각 파티에 속한 사람
vector<vector<int>> party(51);

// 진실을 아는 사람이 없을 때만 과장된 이야기 가능
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// n: 사람의 수, m: 파티의 수
	cin >> n >> m;


	// know: 진실을 아는 사람의 수
	cin >> know;

	// 진실을 아는 사람 제시
	for (int i = 0; i < know; i++)
	{
		// num: 진실을 아는 사람의 번호 (1~50)
		int num;

		cin >> num;

		q.push(num);
	}

	// 각 파티마다 오는 사람 수 계산(i=0: 첫번째파티/i=1: 두번째파티...)
	for (int i = 0; i < m; i++)
	{
		int come;

		cin >> come;

		for (int j = 0; j < come; j++)
		{
			int num;
			cin >> num;

			party[i].push_back(num);
		}
	}

	// 진실 퍼트리기
	while (!q.empty())
	{
		int x = q.front();

		//cout << "===== x = " << x << "=====\n";

		q.pop();

		for (int i = 0; i < m; i++)
		{
			bool flag = false;

			for (int j = 0; j < party[i].size(); j++)
			{
				int nx = party[i][j];

				if (x == nx) {
					flag = true;
					//cout << x << " " << nx << "\n";
					break;
				}
			}

			if (arr[i]) continue;

			if (flag) {
				for (int j = 0; j < party[i].size(); j++)
				{
					int nx = party[i][j];

					if (x != nx) {
						//cout << "i= " << i << " push " << nx << "\n";
						q.push(nx);
						
					}
				}
			}

			if(flag) arr[i] = 1;
			
		}
	}

	for (int i = 0; i < m; i++)
		if (!arr[i]) lie++;

	cout << lie;
	
}


