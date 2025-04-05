#include <bits/stdc++.h>

using namespace std;

int n, l;
int arr[101][101];
int cnt = 0;

bool check(vector<int>& v) {
    bool slope[101] = {false};

    // 지나갈 수 있는 길 체크
    for (int i=1;i<v.size();i++) {
        int prev = v[i-1];
        int cur = v[i]; // 가려고 하는 칸

        if (prev == cur) continue;

        if (abs(prev-cur) > 1) return false;

        // 오르막 2 2 2 3 3 3
        if (prev + 1 == cur) {
            for (int j=i-1;j>=i-l;j--) {
                if (j < 0 || v[j] != prev || slope[j]) return false;
                slope[j] = true;
            }
        }
        // 내리막 3 3 3 2 2 2
        else if (prev - 1 == cur) {
            for (int j=i;j<i+l;j++) {
                if (j >= n || v[j] != cur || slope[j]) return false;
                slope[j] = true;
            }
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l;

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }

    // 행 검사
    for (int i=0;i<n;i++) {
        vector<int> row;

        for (int j=0;j<n;j++) {
            row.push_back(arr[i][j]);
        }

        if (check(row)) cnt++;
        
    }

    // 열 검사
    for (int j=0;j<n;j++) {
        vector<int> col;

        for (int i=0;i<n;i++) {
            col.push_back(arr[i][j]);
        }

        if (check(col)) cnt++;
    }

    cout << cnt;
}
