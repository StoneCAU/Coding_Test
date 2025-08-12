#include <bits/stdc++.h>

using namespace std;

int n;
long long x;
long long len[51];
long long pat[51];

long long play(int level, long long pos) {
    // 시작(pos ~ pos + len[level] - 1), 끝(len[n]-x ~ len[n]-1)
    // 시작의 마지막 인덱스 > 끝의 첫번째 인덱스 -> 안 겹침 조건
    if (pos + len[level] - 1 < len[n] - x) return 0;
    // 먹은 길이에 확정적으로 포함되면 패티 갯수 전부 리턴 (범위 내)
    if (pos >= len[n] - x) return pat[level];
    // 레벨0은 패티 하나만 있으므로 1을 리턴
    if (level == 0) return 1;

    // B | L(N-1) | P | L(N-1) | B
    long long res = 0;
    res += play(level-1, pos+1); // 가운데 P 기준 왼쪽 계산
    if (pos + 1 + len[level-1] >= len[n] - x) res++; // 가운데 계산
    res += play(level-1, pos + len[level - 1] + 2); // 가운데 P 기준 오른쪽 계산

    return res;
}

// 레벨0버거 P(패티)
// 레벨1버거 B(번) P(레벨0버거) P(패티) P(레벨0버거)  B(번)
// 레벨2버거 B(번) BPPPB(레벨1버거) P BPPPB(레벨1버거) B(번)
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;

    len[0] = 1;
    pat[0] = 1;

    // 전처리
    for (int i=1;i<=n;i++) {
        len[i] = 2 * len[i-1] + 3;
        pat[i] = 2 * pat[i-1] + 1;
    }

    cout << play(n, 0);
}
