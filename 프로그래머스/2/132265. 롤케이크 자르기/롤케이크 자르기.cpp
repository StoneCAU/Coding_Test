#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int M = 0;
    
    unordered_map<int,int> m;
    set<int> s;
    
    for (int i=0;i<topping.size();i++) {
        m[topping[i]]++;
    }    
        
    for (int i=topping.size()-1;i>=0;i--) {
        m[topping[i]]--;
        if (m[topping[i]] == 0) m.erase(topping[i]);
        s.insert(topping[i]);
        
        if (m.size() == s.size()) {
            if (M == m.size()) {
                answer++;
            }
            else if (M < m.size()) {
                M = m.size();
                answer = 1;
            }
        }
    } 

    return answer;
}