#include <bits/stdc++.h>

using namespace std;

int n, m;

deque<int> dodo;
deque<int> su;
deque<int> Dground;
deque<int> Sground;

void check() {
    bool dodo_ring = false;
    if (!Dground.empty() && Dground.front() == 5) dodo_ring = true;
    if (!Sground.empty() && Sground.front() == 5) dodo_ring = true;

    bool su_ring = false;
    if (!Dground.empty() && !Sground.empty() &&
        Dground.front() + Sground.front() == 5) {
        su_ring = true;
    }

    if (dodo_ring) {
        for (int i = Sground.size() - 1; i >= 0; i--) {
            dodo.push_back(Sground[i]);
        }
        for (int i = Dground.size() - 1; i >= 0; i--) {
            dodo.push_back(Dground[i]);
        }
        Sground.clear();
        Dground.clear();
    }
    else if (su_ring) {
        for (int i = Dground.size() - 1; i >= 0; i--) {
            su.push_back(Dground[i]);
        }
        for (int i = Sground.size() - 1; i >= 0; i--) {
            su.push_back(Sground[i]);
        }
        Dground.clear();
        Sground.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // deque 초기화
    for (int i = 0; i < n; i++) {
        int dNum, sNum;
        cin >> dNum >> sNum;
        dodo.push_front(dNum);
        su.push_front(sNum);
    }

    // m 번의 게임 진행
    for (int i = 1; i <= m; i++) {
        if (i % 2 == 1) {
            int card = dodo.front();
            dodo.pop_front();
            Dground.push_front(card);

            if (dodo.empty()) {
                cout << "su";
                return 0;
            }
        }
        else {
            int card = su.front();
            su.pop_front();
            Sground.push_front(card);
            
            if (su.empty()) {
                cout << "do";
                return 0;
            }
        }

        // 종을 치는 조건 확인
        check();

        // 게임 종료 조건 확인
        if (dodo.empty() && su.empty()) {
            cout << "dosu";
            return 0;
        }
        if (dodo.empty()) {
            cout << "su";
            return 0;
        }
        if (su.empty()) {
            cout << "do";
            return 0;
        }
    }

    // m번 진행 후 카드 개수 비교
    if (dodo.size() > su.size()) {
        cout << "do";
    }
    else if (dodo.size() < su.size()) {
        cout << "su";
    }
    else {
        cout << "dosu";
    }
}