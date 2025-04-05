#include <bits/stdc++.h>

using namespace std;

int n, b, c;
vector<int> st;
long long int cnt = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=0;i<n;i++) {
        int num;
        cin >> num;

        st.push_back(num);
    }

    cin >> b >> c;

    for (int i=0;i<n;i++) {
        // 감독관 계산
        st[i] -= b;
        cnt++;

        // 부감독관 계산
        if (st[i] > 0) {
            cnt += st[i] / c;

            if (st[i] % c > 0) cnt++;
        }
    }

    cout << cnt;

}
