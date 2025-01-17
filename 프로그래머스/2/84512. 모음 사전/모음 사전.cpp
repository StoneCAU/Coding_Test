#include <string>
#include <vector>
#include <iostream>

using namespace std;

int cnt = 0;
int answer;

void dfs(string str, string word) {    
    char c[5] = {'A', 'E', 'I', 'O', 'U'};
    
    if (str == word) {
        answer = cnt;
        return;
    }
        
    for (int i=0;i<5;i++) {
        if (str.length() < 5) {
            cnt++;
            dfs(str+c[i], word);
        }
    }
}

int solution(string word) {
    dfs("", word);
    return answer;
}