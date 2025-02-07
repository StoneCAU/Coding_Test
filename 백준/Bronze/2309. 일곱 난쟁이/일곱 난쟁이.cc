#include <bits/stdc++.h>

using namespace std;

int main() {
	vector<int> v;
	int sum = 0;

	for (int i = 0; i < 9; i++) {
		int num;
		cin >> num;

		v.push_back(num);
		sum += num;
	}

	sort(v.begin(), v.end());
	
	for (int i = 0; i < 9; i++) {
		int temp = sum;
		temp -= v[i];

		for (int j = i + 1; j < 9; j++) {
			temp -= v[j];

			if (temp == 100) {
				for (int k = 0; k < 9; k++) {
					if (k == i || k == j) continue;
					cout << v[k] << "\n";
				}
				return 0;
			}

			temp += v[j];
		}
	}
}