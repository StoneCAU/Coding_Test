#include<bits/stdc++.h>

using namespace std;

int n,l;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    vector<int> h(n);
    for (int i=0;i<n;i++) {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    for (int i=0;i<n;i++) {
        int f = h[i];

        if (f <= l) l++;
        else break;
    }

    cout << l;
}
