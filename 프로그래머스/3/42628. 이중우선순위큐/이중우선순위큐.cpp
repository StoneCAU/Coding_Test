#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    multiset<int> mt;

    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));
        
        if (op == 'I') {
            mt.insert(num);
        }
        else if (op == 'D' && num == 1) {
            if (mt.empty()) continue;
            auto it = --mt.end();
            mt.erase(it);
        }
        else if (op == 'D' && num == -1) {
            if (mt.empty()) continue;
            auto it = mt.begin();
            mt.erase(it);
        }

    }
    
    if (mt.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(*--mt.end());
        answer.push_back(*mt.begin());
    }

    return answer;
}