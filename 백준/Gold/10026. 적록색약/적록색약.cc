#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int n;
char normal[101][101];
char diff[101][101];
int visited[101][101];
int visited2[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

queue<pair<int, int>> q;

void bfs(int x, int y)
{
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = nx + dx[i];
            int yy = ny + dy[i];

            if (xx >= 0 && xx < n && yy >= 0 && yy < n)
            {
                if (!visited[xx][yy] && normal[nx][ny] == normal[xx][yy])
                {
                    visited[xx][yy] = 1;
                    q.push({ xx, yy });
                }
            }
        }
    }
}

void bfs2(int x, int y)
{
    q.push({ x,y });
    visited[x][y] = 1;

    while (!q.empty())
    {
        int nx = q.front().first;
        int ny = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = nx + dx[i];
            int yy = ny + dy[i];

            if (xx >= 0 && xx < n && yy >= 0 && yy < n)
            {
                if (!visited2[xx][yy] && diff[nx][ny] == diff[xx][yy])
                {
                    visited2[xx][yy] = 1;
                    q.push({ xx, yy });
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int cntN = 0;
    int cntD = 0;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;

        for (int j = 0; j < n; j++)
        {

            normal[i][j] = temp[j];

            if (temp[j] == 'G') {
                temp[j] = 'R';
                diff[i][j] = temp[j];
            }
            else diff[i][j] = temp[j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j]) continue;
            bfs(i, j);
            cntN++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited2[i][j]) continue;
            bfs2(i, j);
            cntD++;
        }
    }

    cout << cntN << " " << cntD;

}
