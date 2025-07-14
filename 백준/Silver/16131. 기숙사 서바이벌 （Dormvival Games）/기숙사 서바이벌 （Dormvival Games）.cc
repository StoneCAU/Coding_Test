#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int room[101]; // room[i] = j : i번 방에 j학번 학생이 있음
int kimochi = 0;
int streak = 0;
int maxStreak = 0;
int hong = 1, jo = a; // 현재 방 위치

// 1번 ~ N번의 학생 존재, 총 M 주 차마다 방을 변경
// 첫 주는 번호대로 들어감. 둘째주부터 상벌점에 따라 두 방을 교환한다
// 1. 최고의 방(1) 부터 최악의 방(N) 존재
// 2. 1 ~ N 까지 인접한 방만 교환
// 3. 상벌점(0점)은 매주 초기화된다(바꾸고 초기화 한다는 의미)

void initRooms() {
    for (int i=1;i<=n;i++) {
        room[i] = i;
    }
    jo = a;
}

vector<int> initScores() {
    vector<int> score(n+1);

    // 상점
    for (int j=1;j<=n;j++) {
        cin >> score[j];
    }

    // 벌점
    for (int j=1;j<=n;j++) {
        int lose;
        cin >> lose;
        score[j] -= lose;
    }

    return score;
}

// 결국에 뒷쪽방이 더 클 때 바꾼다는 의미.
// idx = 방 번호
void change(vector<int>& score, int idx) {
    // 1. hong(방 번호), jo(방 번호) 위치 반영
    if (idx == hong) hong++;
    else if (idx+1 == hong) hong--;

    if (idx == jo) jo++;
    else if (idx+1 == jo) jo--;

    // 1. 사람 바꿈
    int temp = room[idx];
    room[idx] = room[idx+1];
    room[idx+1] = temp;

    // 2. 보정 점수 반영
    score[room[idx]] -= 2;; // 방 좋아짐
    score[room[idx+1]] += 2; // 방 나빠짐
}

void areYouKimochi() {
    if (abs(hong - jo) <= b) {
        kimochi++;
        streak++;
        maxStreak = max(streak, maxStreak);
    }
    else {
        streak = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b >> m;

    // 첫 주차 초기화
    initRooms();
    areYouKimochi();

    // M-1번의 주 차 수행
    for (int i=0;i<m-1;i++) {
        // 전 주의 점수(학번 순)
        vector<int> score = initScores();

        // 1번 room부터 n-1번 room 순서대로.
        // score[학번], room[방 번호] = 학번, j: 방번호
        for (int j=1;j<=n-1;j++) {
            int front = score[room[j]];
            int back = score[room[j+1]];

            // 좋은 방 0점 이상, 나쁜 방 음수 일때 스킵
            if (front >= 0 && back < 0) continue;

            // 두 방의 점수가 모두 0이상 일 때
            if (front >= 0 && back >= 0) {
                if (back - front >= 2) {
                    change(score, j);
                }
            }

            // 앞쪽방 음수, 뒷쪽방 양수일때
            if (front < 0 && back >= 0) {
                change(score, j);
            }

            // 두 방 모두 음수일 때
            if (front < 0 && back < 0) {
                if (back - front >= 4) {
                    change(score, j);
                }
            }
        }

        // 홍군 방 조군 방 차이
        areYouKimochi();
    }

    cout << kimochi << " " << maxStreak;

}