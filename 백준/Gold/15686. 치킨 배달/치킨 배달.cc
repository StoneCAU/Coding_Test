#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n, m;
int arr[52][52];
int minimum = 1000000;

vector<pair<int, int>> home;
vector<pair<int, int>> chicken;

int calculate(int hx, int hy, int cx, int cy)
{
	//cout << "집: " << hx << " " << hy << "\n";
	//cout << "치킨: " << cx << " " << cy << "\n\n";
	return abs(hx - cx) + abs(hy - cy);
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 1) home.push_back({ i, j });
			if (arr[i][j] == 2) chicken.push_back({ i, j });
		}
	}

	// 조합 - m개의 치킨집 선택
	
	vector<int> v;

	for (int i = 0; i < chicken.size(); i++)
		v.push_back(i);

	vector<int> temp;

	for (int i = 0; i < m; i++)
		temp.push_back(1);

	for (int i = 0; i < v.size() - m; i++)
		temp.push_back(0);

	sort(temp.begin(), temp.end());

	int tot = 0;

	// nCr번 반복
	do
	{
		vector<pair<int, int>> sel;

		// m개 뽑기 반복
		for (int i = 0; i < temp.size(); i++)
		{
			tot = 0; // 총 치킨 거리

			// 뽑은 m개 출력
			if (temp[i] == 1)
			{
				//cout << "push: " << chicken[v[i]].first << " " << chicken[v[i]].second << "\n";
				sel.push_back({ chicken[v[i]].first, chicken[v[i]].second });
				
			}
		}

		// 계산 끝, 다음 경우의 수 실행

		//cout << "\n";


		// v[i]: chicken index
		for (int j = 0; j < home.size(); j++)
		{
			int minD = 1000000;

			for (int k = 0; k < sel.size(); k++)
			{
				// 가구당 최소 치킨거리 계산
				minD = min(minD, calculate(home[j].first, home[j].second, sel[k].first, sel[k].second));
				//cout << j << "가구 최소거리 갱신: " << minD << "\n";
			}

			tot += minD;
			//cout << "tot: " << tot << "\n";
		}

		minimum = min(minimum, tot);
		//cout << "min: " << minimum << "\n";

		sel.clear();

	} while (next_permutation(temp.begin(), temp.end()));

	cout << minimum;

}