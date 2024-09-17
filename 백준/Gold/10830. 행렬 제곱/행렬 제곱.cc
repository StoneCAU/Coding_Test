#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>

using namespace std;

unsigned long long  n, b;

vector<vector<unsigned long long>> mat(6, vector<unsigned long long>(6));
vector<vector<unsigned long long>> temp(6, vector<unsigned long long>(6));

vector<vector<unsigned long long>> calculate(vector<vector<unsigned long long>> matA, vector<vector<unsigned long long>> matB)
{
	vector<vector<unsigned long long>> res(6,vector<unsigned long long>(6));

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				res[i][j] += matA[i][k] * matB[k][j];
			}

			res[i][j] = res[i][j] % 1000;
		}
	}

	return res;
}

vector<vector<unsigned long long>> func(unsigned long long b)
{
	if (b == 1) return temp;

	vector<vector<unsigned long long>> t = func(b / 2);

	if (b % 2 == 0)
		return calculate(t, t);
	else
		return calculate(calculate(t, t), temp);
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> b;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> mat[i][j];
		}
	}

	temp = mat;

	mat = func(b);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (b==1) cout << mat[i][j] % 1000 << " ";
			else cout << mat[i][j] << " ";
		}
		cout << "\n";
	}
	
}


