#include<bits/stdc++.h>

using namespace std;

int n, s;
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    // 동생들의 위치
    for (int i=0;i<n;i++) {
        int num;
        cin >> num;

        v.push_back(num);
    }

    sort(v.begin(), v.end());

    if (n == 1) {
        cout << abs(v[0] - s);
        return 0;
    }

    int d = abs(v[0] - s);
    for (int i=1;i<n;i++) {
        d = gcd(d, abs(v[i] - s));
    }

    cout << d;
}
