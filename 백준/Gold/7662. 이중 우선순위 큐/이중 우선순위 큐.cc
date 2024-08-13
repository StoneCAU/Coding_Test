#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long t, k;


// I n: n을 삽입, D 1: 최댓값 삭제, D -1: 최솟값 삭제
int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	
	for (long long i = 0; i < t; i++)
	{
		cin >> k;

		// 오름차순(min)
		priority_queue<long long, vector<long long>, greater<long long>> pqAsc;

		// 내림차순(max)
		priority_queue<long long, vector<long long>, less<long long>> pqDesc;

		unordered_map<long long, long long> m;

		for (long long j = 0; j < k; j++)
		{
			char op;
			long long n;

			cin >> op >> n;

			if (op == 'I')
			{
				pqAsc.push(n);
				pqDesc.push(n);
				
				if (!m[n]) m[n] = 1;
				else m[n]++;
			}
			else if (op == 'D')
			{
				if(pqAsc.empty() || pqDesc.empty()) continue;

				if (n == 1)
				{
					while (1)
					{
						if (pqDesc.empty()) break;

						long long num = pqDesc.top();

						if (!m[num]) {
							pqDesc.pop();
							continue;
						}

						pqDesc.pop();
						m[num]--;

						if (pqDesc.empty()) break;

						if (m[num] == 0)
						{
							while (1)
							{
								if(pqDesc.top() == num) pqDesc.pop();
								if (pqDesc.top() != num || pqDesc.empty()) break;
							}
						}

						break;
					}
				}
				else if (n == -1)
				{
					while (1) 
					{
						if (pqAsc.empty()) break;

						long long num = pqAsc.top();

						if (!m[num]) {
							pqAsc.pop();
							continue;
						}

						pqAsc.pop();
						m[num]--;

						if (pqAsc.empty()) break;

						if (m[num] == 0)
						{
							while(1)
							{
								if(pqAsc.top() == num) pqAsc.pop();
								if (pqAsc.top() != num || pqAsc.empty()) break;
							}
						}

						break;
					}
				}
			}

		}

		while (1)
		{
			if (pqAsc.empty()) break;

			int num = pqAsc.top();

			if (!m[num]) pqAsc.pop();

			if (m[num]) break;
		}

		while (1)
		{
			if (pqDesc.empty()) break;

			int num = pqDesc.top();

			if (!m[num]) pqDesc.pop();

			if (m[num]) break;
		}

		if (pqAsc.empty() || pqDesc.empty()) cout << "EMPTY\n";
		else cout << pqDesc.top() << " " << pqAsc.top() << "\n";
	}
	
	
	

}