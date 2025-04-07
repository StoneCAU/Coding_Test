#include <bits/stdc++.h>

using namespace std;

int n;
int A[21][21]; // 인구 수
int temp[21][21]; // 경계
int ans = 1000000000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    // 완탐
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            for (int d1 = 1; d1 < n; d1++) {
                for (int d2 = 1; d2 < n; d2++) {
                    if (x + d1 + d2 > n) continue;
                    if (y + d2 > n) continue;
                    if (y - d1 < 1) continue;

                    memset(temp, 0, sizeof(temp));

                    // 경계선
                    for (int i = 0; i <= d1; i++) temp[x + i][y - i] = 5;
                    for (int i = 0; i <= d2; i++) temp[x + i][y + i] = 5;
                    for (int i = 0; i <= d2; i++) temp[x + d1 + i][y - d1 + i] = 5;
                    for (int i = 0; i <= d1; i++) temp[x + d2 + i][y + d2 - i] = 5;

                    // 5번 선거구 내부 채우기
                    for (int r = x + 1; r < x + d1 + d2; r++) {
                        bool is_inside = false;
                        for (int c = 1; c <= n; c++) {
                            if (temp[r][c] == 5) is_inside = !is_inside;
                            if (is_inside) temp[r][c] = 5;
                        }
                    }

                    // 1번 선거구
                    for (int r = 1; r < x + d1; r++) {
                        for (int c = 1; c <= y; c++) {
                            if (temp[r][c] == 5) break;
                            temp[r][c] = 1;
                        }
                    }

                    // 2번 선거구
                    for (int r = 1; r <= x + d2; r++) {
                        for (int c = n; c > y; c--) {
                            if (temp[r][c] == 5) break;
                            temp[r][c] = 2;
                        }
                    }

                    // 3번 선거구
                    for (int r = x + d1; r <= n; r++) {
                        for (int c = 1; c < y - d1 + d2; c++) {
                            if (temp[r][c] == 5) break;
                            temp[r][c] = 3;
                        }
                    }

                    // 4번 선거구
                    for (int r = x + d2 + 1; r <= n; r++) {
                        for (int c = n; c >= y - d1 + d2; c--) {
                            if (temp[r][c] == 5) break;
                            temp[r][c] = 4;
                        }
                    }

                    // 각 선거구의 인구 수 계산
                    int people[6] = {0};
                    for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= n; j++) {
                            int zone = temp[i][j];
                            if (zone == 0) zone = 5;
                            people[zone] += A[i][j];
                        }
                    }

                    // 최대값과 최소값 차이 계산
                    int max_val = *max_element(people + 1, people + 6);
                    int min_val = *min_element(people + 1, people + 6);
                    ans = min(ans, max_val - min_val);
                }
            }
        }
    }

    cout << ans;
    return 0;
}
