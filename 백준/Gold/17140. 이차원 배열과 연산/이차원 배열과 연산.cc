#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int r, c, k;
int arr[102][102];
int cnt = 0;
int row = 3;
int col = 3;

unordered_map<int, int> m;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
    // 두번째 값으로 비교
    if (a.second < b.second) {
        return true;
    }
    else if (a.second > b.second) {
        return false;
    }
    else {
        // 두번째 값이 같으면 첫번째 값으로 비교
        return a.first < b.first;
    }
}

void R()
{
    int temp = col;

    for (int i = 1; i <= row; i++)
    {
        m.clear();

        for (int j = 1; j <= col; j++)
        {
            if (arr[i][j] == -1 || arr[i][j] == 0) continue;
            if (!m[arr[i][j]]) m[arr[i][j]] = 1;
            else m[arr[i][j]]++;
        }

        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);

        int j = 1;

        for (auto it = v.begin(); it != v.end(); ++it)
        {
            arr[i][j] = it->first;
            arr[i][j + 1] = it->second;

            j += 2;
        }

        if (m.size() * 2 < temp)
        {
            for (int j = m.size() * 2 + 1; j <= temp; j++)
            {
                arr[i][j] = 0;
            }
        }

        col = max(col, (int)m.size() * 2);

        v.clear();
    }

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (arr[i][j] == -1) arr[i][j] = 0;
        }
    }

}

void C()
{
    int temp = row;

    for (int i = 1; i <= col; i++)
    {
        m.clear();

        for (int j = 1; j <= row; j++)
        {
            if (arr[j][i] == -1 || arr[j][i] == 0) continue;
            if (!m[arr[j][i]]) m[arr[j][i]] = 1;
            else m[arr[j][i]]++;
        }

        vector<pair<int, int>> v(m.begin(), m.end());
        sort(v.begin(), v.end(), cmp);

        int j = 1;

        for (auto it = v.begin(); it != v.end(); ++it)
        {
            arr[j][i] = it->first;
            arr[j + 1][i] = it->second;

            j += 2;
        }

        if (m.size() * 2 < temp)
        {
            for (int j = m.size() * 2 + 1; j <= temp; j++)
            {
                arr[j][i] = 0;
            }
        }

        row = max(row, (int)m.size() * 2);

        v.clear();
    }

    for (int i = 1; i <= col; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (arr[j][i] == -1) arr[j][i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> k;
 
    fill(&arr[0][0], &arr[0][0] + 102 * 102, -1);

    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    while (1)
    { 
        if (arr[r][c] == k) break;

        if (row >= col) R();
        else C();

        cnt++;

        /*
        cout << "\n";
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        */

        if (cnt == 101) break;

    }

    if (cnt == 101) cout << "-1";
    else cout << cnt;
    

}
