#include <bits/stdc++.h>

using namespace std;

int n,l;
vector<pair<int,int>> v;
int res = 0;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i=0;i<n;i++) {
        int s,e;
        cin >> s >> e;

        //
        v.push_back({s, e-1});
    }

    sort(v.begin(), v.end());
    
    // 현재 놓아얄 위치
    int cur = v[0].first;

    for (int i=0;i<v.size();i++) {
        int s = v[i].first;
        int e = v[i].second;

        if (s < cur) s = cur;

        //cout << "\n";
// 1 6
        // 8 12
        // 13 17
        
        // 필요 널빤지 수
        int cnt = (e-s+1) / l;
        if ((e-s+1) % l > 0) cnt++;

        cur = s + cnt * l;
        
        res += cnt;

        
    }
    cout << res;
}

