#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int r, c, t;
bool chk = false;
int up;
int down;
int arr[51][51];
int temp[51][51];
bool dust[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void bfs()
{
    while (!q.empty())
    {
        int xx = q.front().first;
        int yy = q.front().second;
        int cnt = 0;
        int div = arr[xx][yy] / 5;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
            if (arr[nx][ny] == -1) continue;
            dust[nx][ny] = true;
            temp[nx][ny] += div;
            cnt++;
        }

        temp[xx][yy] -= div * cnt;
    }
}

void purify()
{
    // 위(반시계)
    // 상 -> 하
    for (int i = up-1; i >= 0; i--)
    {
        if (i == up-1)
        {
            arr[up-1][0] = 0;
            dust[up-1][0] = false;
        }
        else
        {
            arr[i + 1][0] = arr[i][0];
            if (arr[i + 1][0]) dust[i + 1][0] = true;
            arr[i][0] = 0;
            dust[i][0] = false;
        }
    }

    // 오 -> 왼
    for (int i = 1; i < c; i++)
    {
        arr[0][i-1] = arr[0][i];
        if (arr[0][i-1]) dust[0][i-1] = true;
        arr[0][i] = 0;
        dust[0][i] = false;
    }

    // 하 -> 상
    for (int i = 1; i <= up; i++)
    {
        arr[i-1][c-1] = arr[i][c-1];
        if (arr[i-1][c - 1]) dust[i-1][c - 1] = true;
        arr[i][c-1] = 0;
        dust[i][c-1] = false;
    }

    // 왼 -> 오
    for (int i = c - 2; i >= 1; i--)
    {
        arr[up][i + 1] = arr[up][i];
        if (arr[up][i + 1]) dust[up][i] = true;
        arr[up][i] = 0;
        dust[up][i] = false;
    }

    // 아래(시계)
    // 하 -> 상
    for (int i = down + 1; i < r; i++)
    {
        if (i == down+1)
        {
            arr[down + 1][0] = 0;
            dust[down + 1][0] = false;
        }
        else
        {
            arr[i - 1][0] = arr[i][0];
            if (arr[i - 1][0]) dust[i - 1][0] = true;
            arr[i][0] = 0;
            dust[i][0] = false;
        }
    }

    // 오 -> 왼
    for (int i = 1; i < c; i++)
    {
        arr[r-1][i - 1] = arr[r - 1][i];
        if (arr[r - 1][i - 1]) dust[r - 1][i - 1] = true;
        arr[r - 1][i] = 0;
        dust[r - 1][i] = false;
    }


    // 상 -> 하
    for (int i = r - 2; i >= down; i--)
    {
        arr[i + 1][c-1] = arr[i][c - 1];
        if (arr[i + 1][c - 1]) dust[i + 1][c - 1] = true;
        arr[i][c - 1] = 0;
        dust[i][c - 1] = false;
    }

    // 왼 -> 오
    for (int i = c-2; i >= 1; i--)
    {
        arr[down][i + 1] = arr[down][i];
        if (arr[down][i + 1]) dust[down][i] = true;
        arr[down][i] = 0;
        dust[down][i] = false;
    }

}

void push()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j]) q.push({ i,j });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> c >> t;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j]) {
                q.push({ i,j });
                dust[i][j] = true;
            }

            if (arr[i][j] == -1 && !chk)
            {
                up = i;
                down = i + 1;
                chk = true;
            }
        }
    }

    while (t--)
    {
        copy(&arr[0][0], &arr[0][0] + 51 * 51, &temp[0][0]);

        bfs();

        copy(&temp[0][0], &temp[0][0] + 51 * 51, &arr[0][0]);

        purify();

        push();

    }
   
    int cnt = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (arr[i][j] == -1) continue;
            cnt += arr[i][j];
        }
    }

    cout << cnt;


}
