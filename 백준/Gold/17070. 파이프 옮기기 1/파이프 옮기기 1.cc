#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n;
int cnt = 0;
int arr[18][18];
int dx[] = { 0,1,1 };
int dy[] = { 1,1,0 };

void func(int x, int y, int s)
{
    if (x == n && y == n)
    {
        cnt++;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        if (i == 0 && s == 2) continue;
        if (i == 1 && arr[x+1][y] ==1) continue;
        if (i == 1 && arr[x][y+1] == 1) continue;
        if (i == 2 && s == 0) continue;

        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx <= 0 || nx > n || ny <= 0 || ny > n) continue;
        if (arr[nx][ny] == 1) continue;
        
        func(nx, ny, i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }


    func(1, 2, 0);

    cout << cnt;

}
