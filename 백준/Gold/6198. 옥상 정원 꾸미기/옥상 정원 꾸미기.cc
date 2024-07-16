#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int n;
long long cnt = 0;

stack<int> stk;

int main() {

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;

		cin >> num;

		if(stk.empty()) stk.push(num);
		else
		{
			int t = stk.top();

			if (t > num) {
				stk.push(num);
				cnt += stk.size() - 1;
			}
			else {
				while (stk.top() <= num) {
					stk.pop();
					if (stk.empty()) break;
				}

				stk.push(num);
				cnt += stk.size() - 1;
			}
		}
	}

	cout << cnt;
	
}