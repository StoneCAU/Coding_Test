#include<bits/stdc++.h>

using namespace std;

int n;
int max_cnt = 0;
vector<int> num;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int prev = n;
        int res = i;
        int cnt = 2;
        vector<int> t;

        t.push_back(n);
        t.push_back(res);

        while (1) {
            int temp = res;
            res = prev - res;
            prev = temp;

            if (res < 0) break;
            t.push_back(res);
            cnt++;
        }

        if (max_cnt < cnt) {
            max_cnt = cnt;
            num = t;
        }
    }

    cout << max_cnt << "\n";
    for (int i=0;i<num.size();i++) {
        cout << num[i];
        if (i != num.size()-1) cout << " ";
    }
}
