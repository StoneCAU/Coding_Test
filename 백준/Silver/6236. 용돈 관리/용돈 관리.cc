#include <bits/stdc++.h>

using namespace std;

int n, m;
int k = INT_MAX;

// 현우는 N일 동안 돈을 쓸 것이다
// 정확히 M번만 통장에서 돈을 빼서 사용할 것
// 이 떄, 인출 단위인 K원의 최소값을 구하라
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    vector<int> money;
    for (int i=0;i<n;++i) {
        int num;
        cin >> num;
        money.push_back(num);
    }

    int low = *max_element(money.begin(), money.end());;
    int high = accumulate(money.begin(), money.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;

        int sum = 0; // 현재 인출 횟수
        int cur = 0; // 현재 가지고 있는 돈
        for (int i=0;i<n;++i) {
            int use = money[i];

            // 돈이 부족하면 인출해야지
            if (use > cur) {
                // 인출하기 (왜 +=이 아니냐면, 부족하면 넣는다 했음)
                cur = mid;
                sum++;
            }

            // 사용하기
            cur -= use;
        }

        if (sum <= m) {
            k = mid;
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    cout << k;
}