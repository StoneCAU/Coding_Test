#include <bits/stdc++.h>
using namespace std;

char star[6562][6532];

void recursive(int n, int x, int y)
{
    if (n == 1) {
        star[x][y] = '*';
        return;
    }

    int div = n / 3;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                for (int k = x + div; k < x + 2 * div; k++) {
                    for (int l = y + div; l < y + 2 * div; l++) {
                        star[k][l] = ' ';
                    }
                }
            } else {
                recursive(div, x + i * div, y + j * div);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    recursive(n, 0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << star[i][j];
        }
        cout << "\n";
    }
}
