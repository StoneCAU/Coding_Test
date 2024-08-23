#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
int batter[51][10];
int temp[10];
int cur = -1;
int out = 0;
int M = 0;
int score = 0;
bool base[4];
int why = 0;

void play()
{

	out = 0;
	fill(base, base + 4, false);

	while (out != 3)
	{
		if (cur == 8) cur = 0;
		else cur++;

		// 아웃
		if (temp[cur] == 0) {
			out++;
			//cout << score << " " << cur << "\n";
			continue;
		}

		// 안타
		if (temp[cur] == 1)
		{
			// 주자 없음 -> 1루
			if (!base[0] && !base[1] && !base[2]) base[0] = true;

			// 1루 -> 1,2루
			else if (base[0] && !base[1] && !base[2])
			{
				base[1] = true;
			}

			// 1,2루 -> 만루
			else if (base[0] && base[1] && !base[2])
			{
				base[2] = true;
			}

			// 1,3루 -> 1,2루
			else if (base[0] && !base[1] && base[2])
			{
				score++;
				base[1] = true;
				base[2] = false;
			}

			// 만루 -> 만루
			else if (base[0] && base[1] && base[2])
			{
				score++;
			}

			// 2루 -> 1,3루
			else if (!base[0] && base[1] && !base[2])
			{
				base[2] = true;
				base[1] = false;
				base[0] = true;
			}

			// 2,3루 -> 1,3루
			else if (!base[0] && base[1] && base[2])
			{
				score++;
				base[1] = false;
				base[0] = true;
			}

			// 3루 -> 1루
			else if (!base[0] && !base[1] && base[2])
			{
				score++;
				base[2] = false;
				base[0] = true;
			}
		}

		// 2루타
		if (temp[cur] == 2)
		{
			// 주자 없음 -> 2루
			if (!base[0] && !base[1] && !base[2]) base[1] = true;

			// 1루 -> 2,3루
			else if (base[0] && !base[1] && !base[2])
			{
				base[0] = false;
				base[1] = true;
				base[2] = true;
			}

			// 1,2루 -> 2,3루
			else if (base[0] && base[1] && !base[2])
			{
				score++;
				base[0] = false;
				base[2] = true;
			}

			// 1,3루 -> 2,3루
			else if (base[0] && !base[1] && base[2])
			{
				score++;
				base[0] = false;
				base[1] = true;
			}

			// 만루 -> 2,3루
			else if (base[0] && base[1] && base[2])
			{
				base[0] = false;
				score += 2;
			}

			// 2루 -> 2루
			else if (!base[0] && base[1] && !base[2])
			{
				score++;
			}

			// 2,3루 -> 2루
			else if (!base[0] && base[1] && base[2])
			{
				score += 2;
				base[2] = false;
			}

			// 3루 -> 2루
			else if (!base[0] && !base[1] && base[2])
			{
				score++;
				base[2] = false;
				base[1] = true;
			}
		}

		// 3루타
		if (temp[cur] == 3)
		{
			// 주자 없음 -> 3루
			if (!base[0] && !base[1] && !base[2]) base[2] = true;

			// 1루 -> 3루
			else if (base[0] && !base[1] && !base[2])
			{
				score++;
				base[0] = false;
				base[2] = true;
			}

			// 1,2루 -> 3루
			else if (base[0] && base[1] && !base[2])
			{
				score += 2;
				base[0] = false;
				base[1] = false;
				base[2] = true;
			}

			// 1,3루 -> 3루
			else if (base[0] && !base[1] && base[2])
			{
				score += 2;
				base[0] = false;
			}

			// 만루 -> 3루
			else if (base[0] && base[1] && base[2])
			{
				base[0] = false;
				base[1] = false;
				score += 3;
			}

			// 2루 -> 3루
			else if (!base[0] && base[1] && !base[2])
			{
				base[1] = false;
				base[2] = true;
				score++;
			}

			// 2,3루 -> 3루
			else if (!base[0] && base[1] && base[2])
			{
				score += 2;
				base[1] = false;
			}

			// 3루 -> 3루
			else if (!base[0] && !base[1] && base[2])
			{
				score++;
			}
		}

		// 홈런
		if (temp[cur] == 4)
		{
			int num = 0;

			for (int i = 0; i < 3; i++)
			{
				if (base[i]) num++;
			}

			if (num == 0) score++;
			else if (num == 1) score += 2;
			else if (num == 2) score += 3;
			else score += 4;

			fill(base, base + 4, false);
		}



		M = max(M, score);

	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	fill(base, base + 4, false);

	bool first = true;

	cin >> n;


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> batter[i][j];
		}
	}

	vector<int> v;
	for (int i = 0; i < 9; i++) v.push_back(i);
	sort(v.begin(), v.end());

	vector<int> idx;

	do
	{
		idx.clear();
		fill(temp, temp + 9, 0);
		score = 0;
		cur = -1;

		for (int i = 0; i < 9; i++)
		{
			idx.push_back(v[i]);
			//cout << v[i] << " ";
		}
		//cout << "\n";

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				temp[j] = batter[i][idx[j]];
			}

			if (idx[3] == 0) {
				play();
				why++;
			}

		}


	} while (next_permutation(v.begin(), v.end()));


	cout << M;

	
}