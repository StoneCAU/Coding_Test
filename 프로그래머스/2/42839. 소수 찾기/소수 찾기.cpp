#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    
    for (int i=2;i<num;i++) {
        if (num % i == 0) return false;
    }
    
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> s;
    
    sort(numbers.begin(), numbers.end());
    
    do {
        for (int i=0;i<numbers.size();i++) {
            int number = stoi(numbers.substr(0, i+1));
            if (isPrime(number)) s.insert(number);
        }
    } while (next_permutation(numbers.begin(), numbers.end()));
    
    answer = s.size();
    
    return answer;
}