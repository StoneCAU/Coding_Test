#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	map<pair<int,int>, vector<int>> m;

	int n;
	cin >> n;

	// 학생
	for (int i = 1; i <= n; i++) {

		// 학년
		for (int j = 1; j <= 5; j++) {
			// 반
			int num;
			cin >> num; 

			pair<int, int> p;
			p.first = j;
			p.second = num;

			vector<int> students = m[p];
			students.push_back(i);
			m[p] = students;

			//cout << j << "학년 " << num << "반: " << m[p].size() << "\n";
		}
	}

	int M = 0;
	int master = 1;

	// 학생
	for (int i = 1; i <= n; i++) {
		set<int> s;

		// 학년
		for (int j = 1; j <= 5; j++) {
			// 반
			for (int k = 1; k <= 9; k++) {
				pair<int, int> p;
				p.first = j;
				p.second = k;

				// 해당 학년 반의 학생
				vector<int> v = m[p];
				bool chk = false;

				//cout << "\n" << j << "학년 " << k << "반\n";
				for (int a = 0; a < v.size(); a++) {
					//cout << v[a] << " ";

					if (v[a] == i) {
						chk = true;
						break;
					}
				}

				if (chk) {
					//cout << i << " 학생과 같은 반: ";
					for (int a = 0; a < v.size(); a++) {
						if (v[a] == i) continue;
						s.insert(v[a]);
						//cout << v[a] << " ";
					}
				}
				//cout << "\n";
			}
		}

		if (M < s.size()) {
			M = (int)s.size();

			if (M == s.size()) {
				if (master < i) {
					master = i;
				}
			}
			else master = i;
		}
	}

	cout << master;
}