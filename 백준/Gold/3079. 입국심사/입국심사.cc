#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<long long> chk;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;++i) {
        long long t;
        cin >> t;

        chk.push_back(t);
    }

    sort(chk.begin(), chk.end());

    long long start = 1;
    long long end = chk.back() * m;
    long long ans = end;

    while (start <= end) {
        long long mid = (start + end) / 2;
        long long cnt = 0;

        for (int i=0;i<n;++i) {
            cnt += mid / chk[i];
            if (cnt >= m) break;
        }

        if (cnt >= m) {
            ans = min(ans,mid);
            end = mid-1;
        }
        else {
            start = mid+1;
        }
    }

    cout << ans;
}