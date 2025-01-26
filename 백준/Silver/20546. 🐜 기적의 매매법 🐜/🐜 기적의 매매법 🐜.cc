#include <bits/stdc++.h>

using namespace std;

int main() {

	int money;
	cin >> money;

	int jmoney = money;
	int smoney = money;

	int jsum = 0;
	int ssum = 0;

	int up = 0;
	int down = 0;

	int jhave;
	int shave;
	

	int prev;

	for (int i = 0; i < 14; i++) {
		int num;
		cin >> num;

		if (i != 0) {
			if (prev < num) {
				down = 0;
				up++;
			}
			else if (prev > num) {
				up = 0;
				down++;
			}
			else {
				up = 0;
				down = 0;
			}
		}
		
		// 준현
		if (jmoney > num) {
			jsum = jmoney / num;
			jmoney = jmoney % num;
		}

		// 성민
		if (up == 3 && ssum > 0) {
			smoney = ssum * num;
			ssum = 9;
		}
		else if (down == 3 && smoney > num) {
			ssum = smoney / num;
			smoney = smoney % num;
		}

		if (i == 13) {
			jhave = jsum * num + jmoney;
			shave = ssum * num + smoney;
		}

		prev = num;
	}


	if (jhave > shave) cout << "BNP";
	else if (jhave < shave) cout << "TIMING";
	else cout << "SAMESAME";

}