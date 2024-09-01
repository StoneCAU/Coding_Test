#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	stack<char> op;
	string s;

	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{

		// 피연산자는 그대로 출력
		if (s[i] >= 'A' && s[i] <= 'Z') cout << s[i];
		else
		{
			if (s[i] == '(') op.push(s[i]);
			else if (s[i] == '*' || s[i] == '/')
			{
				while (!op.empty())
				{
					if (op.top() != '*' && op.top() != '/') break;

					cout << op.top();
					op.pop();
				}

				op.push(s[i]);
				
			}
			else if (s[i] == '+' || s[i] == '-')
			{
				while (!op.empty())
				{
					if (op.top() == '(') break;

					cout << op.top();
					op.pop();
				}
				
				op.push(s[i]);

			}
			else if (s[i] == ')')
			{
				while (!op.empty())
				{
					if (op.top() == '(')
					{
						op.pop();
						break;
					}

					cout << op.top();
					op.pop();
				}

			}
		}

	}

	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}
	
}


