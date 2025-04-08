#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, m, t;
vector<vector<int>> v;

// 원판 회전 함수
void rotate(int x, int d, int k) {
    for (int i = x - 1; i < n; i += x) {
        deque<int> dq(v[i].begin(), v[i].end());

        for (int r = 0; r < k; r++) {
            if (d == 0) { // 시계 방향
                int back = dq.back();
                dq.pop_back();
                dq.push_front(back);
            } else { // 반시계 방향
                int front = dq.front();
                dq.pop_front();
                dq.push_back(front);
            }
        }

        v[i] = vector<int>(dq.begin(), dq.end());
    }
}

// 인접한 같은 수 제거 함수
bool removeAdjSame() {
    bool hasSame = false;
    vector<vector<bool>> erase(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 0) continue;
            int curr = v[i][j];

            // 같은 원판 내
            if (v[i][(j + 1) % m] == curr) {
                erase[i][j] = erase[i][(j + 1) % m] = true;
                hasSame = true;
            }

            // 다른 원판과
            if (i > 0 && v[i - 1][j] == curr) {
                erase[i][j] = erase[i - 1][j] = true;
                hasSame = true;
            }
            if (i < n - 1 && v[i + 1][j] == curr) {
                erase[i][j] = erase[i + 1][j] = true;
                hasSame = true;
            }
        }
    }

    // 실제로 지우기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (erase[i][j]) v[i][j] = 0;
        }
    }

    return hasSame;
}

// 평균에 따라 조정
void adjustByAverage() {
    int sum = 0, cnt = 0;
    for (const auto& row : v) {
        for (int num : row) {
            if (num > 0) {
                sum += num;
                cnt++;
            }
        }
    }

    if (cnt == 0) return;

    double avg = (double)sum / cnt;
    for (auto& row : v) {
        for (int& num : row) {
            if (num == 0) continue;
            if ((double)num > avg) num--;
            else if ((double)num < avg) num++;
        }
    }
}

// 최종 합 계산
int getTotalSum() {
    int total = 0;
    for (const auto& row : v) {
        for (int num : row) {
            total += num;
        }
    }
    return total;
}

int main() {
    cin >> n >> m >> t;
    v.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    for (int i = 0; i < t; i++) {
        int x, d, k;
        cin >> x >> d >> k;
        rotate(x, d, k);

        if (!removeAdjSame()) {
            adjustByAverage();
        }
    }

    cout << getTotalSum();
    
}
