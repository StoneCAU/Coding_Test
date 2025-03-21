#include <iostream>

using namespace std;

int n;
long long int M = -10000000000;
string expr;

long long int calculate(long long int a, long long int b, char op) {
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else return 0;
}

void dfs(int idx, long long int cur) {
	if (idx >= n) {
		M = max(M, cur);
		return;
	}

	if (idx == 0) {
		dfs(1, expr[0] - '0');
		return;
	}

	char op;
	char nextOp;
	long long int num;
	long long int nextNum;

	// 괄호 X
	op = expr[idx];
	num = expr[idx + 1] - '0';
	
	// 괄호 O
	// 8 * (3 + 5)
	if (idx + 2 < n) {
		nextNum = expr[idx + 3] - '0';
		nextOp = expr[idx + 2];
		long long int bracket = calculate(num, nextNum, nextOp);
		dfs(idx + 4, calculate(cur, bracket, op));
	}

	dfs(idx + 2, calculate(cur, num, op));


}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> expr;
	dfs(0, 0);

	cout << M;
}