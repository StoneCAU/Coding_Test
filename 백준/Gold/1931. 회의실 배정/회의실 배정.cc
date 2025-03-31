#include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
using namespace std;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;

        v.push_back(pair<int, int>(e, s));

    }

    sort(v.begin(), v.end());

    int time = v[0].first;
    int cnt = 1;

    for (int i = 1; i < v.size(); i++)
    {
        if (time <= v[i].second)
        {
            time = v[i].first;
            cnt++;
        }
    }

    cout << cnt;

    
    
}
