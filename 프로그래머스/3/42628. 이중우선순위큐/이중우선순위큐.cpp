#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    int count = 0;

    priority_queue<int> max_pq;
    priority_queue<int, vector<int>, greater<int>> min_pq;

    for (int i = 0; i < operations.size(); i++) {
        char op = operations[i][0];
        int num = stoi(operations[i].substr(2));

        if (op == 'I') {
            max_pq.push(num);
            min_pq.push(num);
            count++;
        }
        else if (op == 'D' && num == 1) {
            if (!max_pq.empty()) {
                int max_val = max_pq.top();
                max_pq.pop();

                vector<int> temp;
                while (!min_pq.empty()) {
                    if (min_pq.top() == max_val) {
                        min_pq.pop();
                        break;
                    }
                    temp.push_back(min_pq.top());
                    min_pq.pop();
                }
                for (int t : temp) min_pq.push(t);

                count--;
            }
        }
        else if (op == 'D' && num == -1) {
            if (!min_pq.empty()) {
                int min_val = min_pq.top();
                min_pq.pop();

                vector<int> temp;
                while (!max_pq.empty()) {
                    if (max_pq.top() == min_val) {
                        max_pq.pop();
                        break;
                    }
                    temp.push_back(max_pq.top());
                    max_pq.pop();
                }
                for (int t : temp) max_pq.push(t);

                count--;
            }
        }

        if (count == 0) {
            max_pq = priority_queue<int>();
            min_pq = priority_queue<int, vector<int>, greater<int>>();
        }
    }

    if (count == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(max_pq.top());
        answer.push_back(min_pq.top());
    }

    return answer;
}