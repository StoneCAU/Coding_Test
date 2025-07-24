#include<bits/stdc++.h>

using namespace std;

int a,b,c;
int X1, X2, Y1, Y2;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> b >> c;
    cin >> X1 >> X2 >> Y1 >> Y2;

    bool X1_range = false, X2_range = false, Y1_range = false, Y2_range = false;

    // 1. Y = Y1, Y = Y2 선과의 교점이 X 범위에 있는지 확인
    if (a != 0) {  // 수직선이 아닌 경우
        // ax + b*Y1 + c = 0에서 x를 구하면: x = -(b*Y1 + c)/a
        int target1 = -b * Y1 - c;  // a*x의 값
        int target2 = -b * Y2 - c;  // a*x의 값

        int m = a * X1;
        int M = a * X2;

        // a가 음수면 부등호 방향이 바뀜
        if (m > M) swap(m, M);

        X1_range = target1 > m && target1 < M;
        X2_range = target2 > m && target2 < M;
    }

    // 2. X = X1, X = X2 선과의 교점이 Y 범위에 있는지 확인
    if (b != 0) {  // 수평선이 아닌 경우
        // a*X1 + by + c = 0에서 y를 구하면: y = -(a*X1 + c)/b
        int target1 = -a * X1 - c;  // b*y의 값
        int target2 = -a * X2 - c;  // b*y의 값

        int m = b * Y1;
        int M = b * Y2;

        // b가 음수면 부등호 방향이 바뀜
        if (m > M) swap(m, M);

        Y1_range = target1 > m && target1 < M;
        Y2_range = target2 > m && target2 < M;
    }

    if (X1_range || X2_range || Y1_range || Y2_range) {
        cout << "Poor";
    }
    else cout << "Lucky";
}