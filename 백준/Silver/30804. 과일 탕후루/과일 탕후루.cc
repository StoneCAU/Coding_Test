#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

int n;
int cnt = 0;
int maxcnt = 0;
int temp = 0;

deque<int> dq;
set<int> s;

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;

		cin >> num;

		dq.push_back(num);
		s.insert(num);
		cnt++;
		


		while(s.size() > 2) {
			
			int t = dq.front();
			dq.pop_front();
			cnt--;


			bool exist = false;

			for (int j = 0; j < dq.size(); j++)
			{
				if (dq[j] == t) {
					exist = true;
					break;
				}
			}

			if (!exist) {
				s.erase(t);
			}

			if (cnt > maxcnt) maxcnt = cnt;
		}

		if (cnt > maxcnt) maxcnt = cnt;

	}

	cout << maxcnt;

	

}