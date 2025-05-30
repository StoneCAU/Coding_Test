#include<bits/stdc++.h>

using namespace std;

int answer = 0;
bool isused1[40]; // 세로
bool isused2[40]; // 대각선 (x+y)
bool isused3[40]; // 대각선 (x-y+n-1)

int m;

void func(int row) {
    if (row == m) {
        answer++;
        return;
    }
    
    // 열(i) 선택
    for (int i=0;i<m;i++) {
        if (!isused1[i] && !isused2[row+i] && !isused3[row-i+m-1]) {
            isused1[i] = true;
            isused2[row+i] = true;
            isused3[row-i+m-1] = true;
            
            func(row+1);
            
            isused1[i] = false;
            isused2[row+i] = false;
            isused3[row-i+m-1] = false;
        }
    }
}

int solution(int n) {
    m=n;
    func(0);
    
    return answer;
}