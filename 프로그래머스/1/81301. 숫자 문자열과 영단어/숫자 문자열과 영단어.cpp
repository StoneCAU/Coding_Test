#include<bits/stdc++.h>

using namespace std;

int solution(string s) {    
    string num[10] = {"zero", "one", "two", "three", "four",
                  "five", "six", "seven", "eight", "nine"};
    
    for (int i=0;i<10;++i) {
        int pos = 0;
        while ((pos = s.find(num[i], pos)) != -1) {
            s.replace(pos, num[i].length(), to_string(i));
            pos += 1;
        }
    }
    
    return stoi(s);
}