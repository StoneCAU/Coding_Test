#include <bits/stdc++.h>
#include <algorithm>
#include<unordered_map>
using namespace std;

int n, k;
int state = 0;
int arr[202];
bool robot[202];

vector<int> v;

void rotate()
{
    int temp = arr[2 * n];
    int temp2 = robot[2 * n];
    copy(&arr[1], &arr[1] + 2 * n - 1, &arr[2]);
    copy(&robot[1], &robot[1] + 2 * n - 1, &robot[2]);
    arr[1] = temp;
    robot[1] = temp2;
    robot[n] = false;
}

void check()
{
    for (int i = 2 * n; i >= 1; i--)
    {
        if (robot[i]) v.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;

    for (int i = 1; i <= n * 2; i++)
    {
        cin >> arr[i];
    }

    fill(robot, robot + 202, false);

    //rotate();

    //for (int i = 1; i <= 2 * n; i++) cout << arr[i] << " ";


    while (1)
    {
        int cnt = 0;
        v.clear();
        state++;

        // 1. 회전
        rotate();

        // 2. 로봇 이동
        check();

        if (!v.empty())
        {
            for (int i = 0; i < v.size(); i++)
            {
                int next = v[i] + 1;
                if (next == 2 * n + 1) next = 1;

                if (robot[next]) continue;
                if (arr[next] == 0) continue;

                robot[next] = true;
                robot[v[i]] = false;
                arr[next]--;

                if (next == n)
                {
                    robot[next] = false;
                }
            }
        }

        // 3. 로봇 올리기
        if (arr[1])
        {
            robot[1] = true;
            arr[1]--;
        }

        // 4. 내구도 체크
        for (int i = 1; i <= 2 * n; i++)
        {
            if (!arr[i]) cnt++;
        }

        if (cnt >= k) break;
    }

    cout << state;

}
